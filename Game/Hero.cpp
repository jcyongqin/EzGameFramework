#include "stdafx.h"
#include "Scene.h"
#include "Node.h"
#include "Hero.h"



Hero::Hero()
{
}


Hero::~Hero()
{
}

bool Hero::create()
{
	return true;
}
bool Hero::create(int x,int y)
{
	Hp = 100;
	Mp = 100;

	cName = L"Hero";
	status = HeroStatus::standUp;
	pos = { x,y };
	srcImg.Destroy();
	srcImg.Load(L"res\\Guan_Yu.png");
	srcRect = RECT{ 0,0,48,64 };
	return true;
}



bool Hero::triger(Node& aNode)
{
	return true;
	if (aNode.cName == L"Wall")
	{
			status = HeroStatus::standUp;
		if (aNode.pos.x > pos.x && aNode.pos.y == pos.y) {
			status = HeroStatus::cantGoRight;
		}
		if (aNode.pos.x < pos.x && aNode.pos.y == pos.y) {
			status = HeroStatus::cantGoLeft;
		}
		if (aNode.pos.x == pos.x && aNode.pos.y > pos.y) {
			status = HeroStatus::cantGoDown;
		}
		if (aNode.pos.x== pos.x && aNode.pos.y < pos.y) {
			status = HeroStatus::cantGoUp;
		}

	}
	return false;
}


bool Hero::draw(CDC &dc)
{

	srcImg.Draw(dc.m_hDC, { pos.x + 1,pos.y - 14,pos.x + 49,pos.y - 14 + 64 }, srcRect);
	return true;
}


bool Hero::update(Scene *scene, int callbk) {
	static int timeOld = 100;
	//scene->makeBattle(this, &);
	// 做出动画 ++ 判断状态位移
	if (callbk == timeOld) {

		if (timeOld < 104)
		{
			scene->timeDelay(this, 100, ++timeOld);
			// 做出动画
			animation();
			// 做出位移
			walk();
		}
		else {
			walk();
			status = HeroStatus::standUp;
			animation();
			timeOld = 100;
		}
	}


	// 响应按键 ++ 状态机
	if (status == HeroStatus::standUp ||
		status == HeroStatus::cantGoDown ||
		status == HeroStatus::cantGoUp ||
		status == HeroStatus::cantGoLeft ||
		status == HeroStatus::cantGoRight)
	{

			if (scene->checkKeyDown(KEY_DOWN) && status != HeroStatus::cantGoDown)
			{
				if (pos.y < 700) {
					status = HeroStatus::goDown;
					scene->timeDelay(this, 1, ++timeOld);
				}
			}
			if (scene->checkKeyDown(KEY_UP) && status != HeroStatus::cantGoUp)
			{
				if (pos.y > 0) {
					status = HeroStatus::goUp;
					scene->timeDelay(this, 1, ++timeOld);
				}
			}
			if (scene->checkKeyDown(KEY_LEFT) && status != HeroStatus::cantGoLeft)
			{
				if (pos.x > 0) {
					status = HeroStatus::goLeft;
					scene->timeDelay(this, 1, ++timeOld);
				}
			}
			if (scene->checkKeyDown(KEY_RIGHT) && status != HeroStatus::cantGoRight)
			{
				if (pos.x < 950) {
					status = HeroStatus::goRight;
					scene->timeDelay(this, 1, ++timeOld);
				}
			}
		

	}
	return true;
}

bool Hero::animation()
{
	/*
	if (status == HeroStatus::standUp) {
	srcRect.left = 0;
	srcRect.right = 48;

	if (status == HeroStatus::goDown || status == HeroStatus::cantGoDown) {
	srcRect.top = 0;
	srcRect.bottom = 64;
	srcRect.left += 48;
	srcRect.right += 48;
	}
	if(status == HeroStatus::goUp || status == HeroStatus::cantGoUp){
	srcRect.top = 192;
	srcRect.bottom = 256;
	srcRect.left += 48;
	srcRect.right += 48;
	}


	if (status == HeroStatus::goLeft || status == HeroStatus::cantGoLeft) {
	srcRect.top = 64;
	srcRect.bottom = 128;
	srcRect.left += 48;
	srcRect.right += 48;
	}

	if (status == HeroStatus::goRight || status == HeroStatus::cantGoRight) {
	srcRect.top = 128;
	srcRect.bottom = 192;
	srcRect.left += 48;
	srcRect.right += 48;
	}

	}
	*/
	switch (status)
	{
	case(HeroStatus::standUp):
		srcRect.left = 0;
		srcRect.right = 48;
		break;
	case(HeroStatus::goDown):
		srcRect.top = 0;
		srcRect.bottom = 64;
		srcRect.left += 48;
		srcRect.right += 48;
		break;
	case(HeroStatus::goUp):
		srcRect.top = 192;
		srcRect.bottom = 256;
		srcRect.left += 48;
		srcRect.right += 48;
		break;
	case(HeroStatus::goLeft):
		srcRect.top = 64;
		srcRect.bottom = 128;
		srcRect.left += 48;
		srcRect.right += 48;
		break;
	case(HeroStatus::goRight):
		srcRect.top = 128;
		srcRect.bottom = 192;
		srcRect.left += 48;
		srcRect.right += 48;
		break;

		break;
	}
	return true;
}

bool Hero::walk()
{
	static int step = 12;

	switch (step)
	{
	case(12):step = 13; break;
	case(13):step = 12; break;
	}

	switch (status) {
	case(HeroStatus::goDown):
		pos.y += step;
		break;
	case(HeroStatus::goUp):
		pos.y -= step;
		break;
	case(HeroStatus::goLeft):
		pos.x -= step;
		break;
	case(HeroStatus::goRight):
		pos.x += step;
		break;
	}
	return true;
}



