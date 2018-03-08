#pragma once
#include "Node.h"
#include "list"
#include <map>


class Director;



class Scene
{
public:
	Scene();
	/**
	 * \brief ����Map:Node���ָ�룬���ڶ�����ǰ
	 * \return ����Scene���ָ��
	 */
	Scene *create();
	Scene *create(Node * node, Director * director);
	virtual ~Scene();
	// ��������
	virtual bool run(CWnd *pWnd);
	bool pushBack(Node *node);
	bool pushFront(Node *node);
	bool onKeyDown(int key);
	bool onKeyUp(int key);
	bool checkKeyDown(int key);
	bool timeDelay(Node *node, DWORD ms, DWORD callbk);
	int getFPS();
	bool makeBattle(Node *, Node *);

	bool changeL2();
	bool changeL3();
	bool end();
	// ��̬����
	static bool time_delay(Node *node, DWORD ms, DWORD callbk, int nTimes, Scene *scene)
	{
		static int timeOld = 100;

		if (nTimes > 0)
		{
			scene->timeDelay(node, ms, ++timeOld);
			return true;
		}
		else {
			if (callbk == timeOld) {
				if (timeOld < 100 + nTimes)
				{
					scene->timeDelay(node, ms, ++timeOld);
					return true;
				}
				else {
					return true;
					timeOld = 100;
				}
			}
			return false;
		}
	}
public:
	int FPS;
protected:
	
	DWORD timeNow();
	bool ckeckTime();
	bool collCheck();
	bool update(Scene *scene);
	virtual bool render(CDC &dc);
protected:
	DWORD timeLast;
	Director *director;
	int mFPS;
	std::list<Node *> nodeList;
	std::map<QWORD, Node * > timeMap;
	std::map<int, bool>   keyMap;
};


