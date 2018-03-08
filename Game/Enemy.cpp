#include "stdafx.h"
#include "Resource1.h"
#include "Enemy.h"
#include"Scene.h"

Enemy::Enemy()
{
	//Enemy::create();
}


Enemy::~Enemy()
{

}


bool Enemy::create()
{
	
	//this->srcImg.Destroy();
	//this->srcImg.Load(ENE_XIAHOU);
	return true;
}


bool Enemy::triger(Node& aNode)
{

	if (aNode.cName == L"Hero" &&chetui==1&&s!=afterfight ) {
		m_Hero = &aNode;
		aNode.pos.y +=50;
		chetui = 0;
		s = fight;
	}
	return true;
}


bool Enemy::draw(CDC &dc)
{
	if (s != afterfight) {
		srcImg.Draw(dc.m_hDC, pos.x + 1, pos.y - 14, 48, 64, srcPoint.x + 1, srcPoint.y, 48, 64);
	}
	return true;
}


bool Enemy::update(Scene* scene, int callbk)
{

	if (Hp <= 0)
	{
		s = afterfight;
		if (oName== L"res\\Battle\\Battle\\hanfu\\ENE_ZL.png") {
			scene->changeL2();
		}
		if (oName == L"res\\Battle\\Battle\\wangzhi\\ENE_FS.png")
		{
			scene->changeL3();
		}
		if (oName == L"res\\Battle\\Battle\\NPC\\LIU_BEI.png")
		{
			scene->end();
		}
	}
	
	if (chetui==0&& s != afterfight)
	{
		scene->makeBattle(m_Hero, this);
	}

	if (0 < Hp&&Hp < 110)
	{
		chetui = 1;
	}

	return true;
}


bool Enemy::create(CString &Name, int x,int y)
{
	Hp = 110;
	s = nofight;
	chetui = 1;
	// 初始化节点
	this->oName = Name;
	this->pos .x= x;
	this->pos.y = y;
	srcPoint = { 0,0 };
	// 加载图片
	
		this->srcImg.Destroy();
		srcImg.Load(Name);
	
	return true;
}


bool Enemy::animation()
{
	return true;

	while (1) {
		for (int i = 0; i < 30; i++) {
			srcPoint.y = 0;
			

			srcPoint.x = srcPoint.x + 48;
			if (srcPoint.x == 144)
				srcPoint.x = 0;
			pos.y += 5;
		}

		for (int i = 0; i < 30; i++) {
			srcPoint.y = 3;
			//ʱ��

			srcPoint.x = srcPoint.x + 48;
			if (srcPoint.x == 144)
				srcPoint.x = 0;
			pos.y -= 5;
		}
	}
}