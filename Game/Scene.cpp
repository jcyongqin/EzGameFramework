#include "stdafx.h"
#include <cmath>
#include "Resource1.h"

#include "Director.h"
#include "Scene.h"
#include <timeapi.h>


#define MAKE_QWORD(_hdw,_ldw) (QWORD(DWORD(_hdw))<< 32 | DWORD(_ldw))

Scene::Scene()
{
}


Scene * Scene::create()
{
	keyMap[KEY_UP] = false;
	keyMap[KEY_DOWN] = false;
	keyMap[KEY_LEFT] = false;
	keyMap[KEY_RIGHT] = false;
	keyMap[KEY_ENTER] = false;
	return nullptr;
}

Scene* Scene::create(Node *node, Director * doctor)
{
	director = doctor;
	//doctor->changeScene(this);
	FPS = 1000;
	keyMap[KEY_UP] = false;
	keyMap[KEY_DOWN] = false;
	keyMap[KEY_LEFT] = false;
	keyMap[KEY_RIGHT] = false;
	keyMap[KEY_ENTER] = false;
	nodeList.push_front(node);
	return this;
}


Scene::~Scene()
{
	for (auto element : nodeList)
	{
		delete element;
	}
}

bool Scene::run(CWnd* pWnd)
{

	ckeckTime();
	collCheck();
	update(this);

	CClientDC dc(pWnd);
	CMemDC mem_dc((CDC &)dc, pWnd);
	render(mem_dc.GetDC());


	return true;
}



bool Scene::pushBack(Node* node)
{
	nodeList.push_back(node);
	return true;
}


bool Scene::pushFront(Node* node)
{
	nodeList.push_front(node);
	return true;
}


bool Scene::onKeyDown(int key)
{
	if (key == 'W')
	{
		keyMap[KEY_UP] = true;
	}
	if (key == 'S')
	{
		keyMap[KEY_DOWN] = true;
	}
	if (key == 'A')
	{
		keyMap[KEY_LEFT] = true;
	}
	if (key == 'D')
	{
		keyMap[KEY_RIGHT] = true;
	}
	if (key == VK_RETURN)
	{
		keyMap[KEY_ENTER] = true;
	}

	return true;
}


bool Scene::onKeyUp(int key)
{
	if (key == 'W')
	{
		keyMap[KEY_UP] = false;
	}
	if (key == 'S')
	{
		keyMap[KEY_DOWN] = false;
	}
	if (key == 'A')
	{
		keyMap[KEY_LEFT] = false;
	}
	if (key == 'D')
	{
		keyMap[KEY_RIGHT] = false;
	}
	if (key == VK_RETURN)
	{
		keyMap[KEY_ENTER] = false;
	}
	return true;
}


bool Scene::checkKeyDown(int key)
{

	if (keyMap[key] == 1)
		return true;
	else
		return false;

}

/**
 * \brief
 * \param ms 延迟ms毫秒后
 * \param callbk update回调时会传入设置的callbk
 * \return
 */
bool Scene::timeDelay(Node *node, DWORD ms, DWORD callbk)
{
	DWORD timeNow = timeGetTime();
	timeMap[MAKE_QWORD(ms + timeNow, callbk)] = node;

	return true;
}

int Scene::getFPS()
{
	return mFPS;
}

bool Scene::makeBattle(Node* hero, Node* enemy)
{
	director->changeScene(hero, enemy, this);
	return true;
}

bool Scene::changeL2()
{
	director->changelevel2();
	return true;
}
bool Scene::changeL3()
{
	director->changelevel3();
	return true;
}
bool Scene::end()
{
	director->end();
	return true;
}

DWORD Scene::timeNow()
{
	return timeGetTime();
}

bool Scene::ckeckTime()
{

	for (auto iter = timeMap.begin(); iter != timeMap.end(); )
	{
		DWORD timeNow = timeGetTime();
		if (timeNow > HIDWORD(iter->first))
		{
			iter->second->update(this, LODWORD(iter->first));
			timeMap.erase(iter++);
		}
		else
		{
			++iter;
		}
	}
	return true;
}


/**
* \brief 碰撞检测，两对象相距50像素触发
* \return
*/
bool Scene::collCheck()
{
	for (auto element = nodeList.begin(); element != nodeList.end(); ++element)
	{
		for (auto rElememt = nodeList.begin(); rElememt != nodeList.end(); ++rElememt)
		{
			double diffSquar = 0;
			diffSquar = std::powl(((*element)->pos.x - (*rElememt)->pos.x), 2) +
				std::powl(((*element)->pos.y - (*rElememt)->pos.y), 2);

			if (diffSquar <= std::powl(50, 2)) {
				(*element)->triger(*(*rElememt));
				(*rElememt)->triger(*(*element));

			}
		}
	}
	return false;
}

bool Scene::update(Scene* scene)
{
	// 检查延时

	// 常规update
	for (auto element : nodeList)
	{
		element->update(this, 0);
	}
	return true;
}


bool Scene::render(CDC& dc)
{
	for (auto element : nodeList)
	{
		element->draw(dc);
	}

	return true;
}


