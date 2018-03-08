#include "stdafx.h"
#include <cmath>
#include "Resource1.h"
#include"Scene.h"
#include "Director.h"
#include <afx.h>
#include"Enemy.h"
#include "Hero.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include"Game.h"
#include "ComScene.h"
#define MAKE_QWORD(_hdw,_ldw) (QWORD(DWORD(_hdw))<< 32 | DWORD(_ldw))


ComScene::ComScene()
{
}


ComScene::~ComScene()
{

}



ComScene * ComScene::create(Node *hero, Node *enemy, Director * director,int  L)
{
	cs_status = CheTui;
	level = L;
	
	this->director = director;
	
	this->hero = hero;
	this->enemy = enemy;


	CImage *img;
	CString str; L"res\\ctrl\\Ctrl_%d.png";
	for (int i = 0; i < 6; ++i)
	{
		img = new CImage();
		str.Format(L"res\\ctrl\\Ctrl_%d.png", i + 1);
		img->Load(str);
		this->btmImgList.push_back(img);
	}

	pic = 1; 
	
	hp =hero->Hp;
	mp = 100;
	hp_X = hp * 3;
	mp_X = mp * 3;

	enemyhp = enemy->Hp;
	enemyhp_X = enemyhp*1.5;

	enemyHp.Load(L"res\\HP.png");
	Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY1.png");
	

	if (level == 1) {
		Back.Load(L"res\\Battle\\Battle_back2.png");
		Enemy.Load(L"res\\Battle\\Battle\\mengtan\\Battle_dao1.png");
	}
	if (level == 2) {
		Back.Load(L"res\\Battle\\Battle_back6.png");
		Enemy.Load(L"res\\Battle\\Battle\\wangzhi\\Battle_FS1.png");
	}
	if (level == 3) {
		Back.Load(L"res\\Battle\\Battle_back1.png");
		Enemy.Load(L"res\\Battle\\Battle\\qinqi\\Battle_qiang1.png");
	}
		
	Hp.Load(L"res\\HP.png");
	Mp.Load(L"res\\MP.png");
	At.Load(L"res\\AT.png");


	return this;
}

bool ComScene::checkKey()
{
	CString asd;
	asd.Format(L"%d\n", cs_status);
	TRACE(asd);

	switch (cs_status)
	{
	case(CheTui):
		if (checkKeyDown(KEY_ENTER)) {
			gy_status = CheTuiHou;
			//hero->pos.x = 100;
			//hero->pos.y = 650;
			//director->changeScene(nullptr, nullptr, nullptr);
		}
		if (checkKeyDown(KEY_LEFT))cs_status = CheTui;
		if (checkKeyDown(KEY_DOWN))	cs_status = JinNengNone;
		if (checkKeyDown(KEY_RIGHT)) cs_status = JinNengGogJi;
		break;
	case(JinNengNone):

		if (checkKeyDown(KEY_ENTER))			cs_status = FanHui;
		if (checkKeyDown(KEY_LEFT))cs_status = CheTui;
		if (checkKeyDown(KEY_DOWN))	cs_status = JinNengNone;
		if (checkKeyDown(KEY_RIGHT)) cs_status = JinNengGogJi;
		break;

	case(JinNengGogJi):
		if (checkKeyDown(KEY_ENTER))gy_status = useGogJi;
		if (checkKeyDown(KEY_LEFT))cs_status = CheTui;
		if (checkKeyDown(KEY_DOWN))	cs_status = JinNengNone;
		if (checkKeyDown(KEY_RIGHT)) cs_status = JinNengGogJi;
		break;
	case(FanHui):
		if (checkKeyDown(KEY_ENTER))cs_status = JinNengNone;
		if (checkKeyDown(KEY_LEFT))cs_status = FanHui;
		if (checkKeyDown(KEY_DOWN))	cs_status = JinNengChiTu;
		if (checkKeyDown(KEY_RIGHT)) cs_status = JinNengKuaiDao;
		break;
	case(JinNengChiTu):
		if (checkKeyDown(KEY_ENTER))gy_status = useChiTu;
		if (checkKeyDown(KEY_LEFT))cs_status = FanHui;
		if (checkKeyDown(KEY_DOWN))	cs_status = JinNengChiTu;
		if (checkKeyDown(KEY_RIGHT)) cs_status = JinNengKuaiDao;
		break;
	case(JinNengKuaiDao):
		if (checkKeyDown(KEY_ENTER))gy_status = useKuaiDao;
		if (checkKeyDown(KEY_LEFT))cs_status = FanHui;
		if (checkKeyDown(KEY_DOWN))	cs_status = JinNengChiTu;
		if (checkKeyDown(KEY_RIGHT)) cs_status = JinNengKuaiDao;
		break;
	}

	return true;
}


#define  T_DELAY 200
bool ComScene::animation()
{
	static int animGongJi = 0;

	static DWORD timeNow = 0;


	switch (gy_status)
	{
	case(CheTuiHou):
		hero->pos.x = 100;
		hero->pos.y = 700;
		enemy->chetui=1;
		//enemy->update(this,0);
			director->changeScene(nullptr, nullptr, nullptr);

			break;
	case (useGogJi):
		switch (animGongJi)
		{
		case(0):
			
			Hero.Destroy();
			Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY2.png");
			animGongJi++;
			break;
		case(1):
			Hero.Destroy();
			Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY3.png");
			animGongJi++;
			break;
		case(2):
			Hero.Destroy();
			Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY4.png");
			animGongJi++;
			break;
		case(3):
			Hero.Destroy();
			Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY5.png");
			animGongJi++;
			break;
		case(4):
			mciSendString(L"play res\\daojian.wav", 0, 0, 0);
			Hero.Destroy();
			Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY1.png");
			animGongJi = 0;
			enemyhp = enemyhp - 10;
			enemy->Hp = enemy->Hp - 10;
	
			if (enemyhp <= 0) {
				director->changeScene(nullptr, nullptr, nullptr);
				break;
			}
			gy_status = GuanYuStatus::staandBy;
			break;
		}

		break;

	case (useChiTu):
		if(mp>=20){
			switch (animGongJi)
			{
			case(0):
				mciSendString(L"play res\\ma.wav", 0, 0, 0); 
				/*
				PlaySound(
					MAKEINTRESOURCE(IDR_WAVE6),
					GetModuleHandle(NULL),
					SND_RESOURCE | SND_ASYNC );
					*/
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL1.png");
				animGongJi++;
				break;
			case(1):
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL2.png");
				animGongJi++;
				break;
			case(2):
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL3.png");
				animGongJi++;
				break;
			case(3):
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL4.png");
				animGongJi++;
				break;
			case(4):
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL5.png");
				animGongJi++;
				break;
			case(5):
				
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY1.png");
				animGongJi = 0;
				gy_status = GuanYuStatus::staandBy;
				enemyhp = enemyhp - 22;
				enemy->Hp = enemy->Hp - 22;
				mp = mp - 20;
				if (enemyhp <= 0) {
					director->changeScene(nullptr, nullptr, nullptr);
					break;
				}
				gy_status = GuanYuStatus::staandBy;
			}
		}

		break;
	case(useKuaiDao):
		if(mp>=15){
			switch (animGongJi)
			{
			case(0):
				

				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL22.png");
				animGongJi++;
				break;
			case(1):
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL23.png");
				animGongJi++;
				break;
			case(2):
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL24.png");
				animGongJi++;
				break;
			case(3):
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\SKILL\\SKILL25.png");
				animGongJi++;
				break;
			case(4):
				mciSendString(L"play res\\death.wav", 0, 0, 0);
				Hero.Destroy();
				Hero.Load(L"res\\Battle\\Battle\\guanyu\\Battle_GY1.png");
				animGongJi = 0;
				enemyhp = enemyhp - 15;
				enemy->Hp = enemy->Hp - 15;

				mp = mp - 15;

				if (enemyhp <= 0) {
					director->changeScene(nullptr, nullptr, nullptr);
					break;
				}
				gy_status = GuanYuStatus::staandBy;
				break;
			}
		}
		break;
	case(staandBy):
		if(level==1){
			switch (animGongJi)
			{
			case(0):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\mengtan\\Battle_dao2.png");
				animGongJi++;
				break;
			case(1):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\mengtan\\Battle_dao3.png");
				animGongJi++;
				break;
			case(2):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\mengtan\\Battle_dao4.png");
				animGongJi++;
				break;
			case(3):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\mengtan\\Battle_dao5.png");
				animGongJi++;
				break;
			case(4):
				mciSendString(L"play res\\daojian.wav", 0, 0, 0);
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\mengtan\\Battle_dao1.png");
				animGongJi = 0;
				hp = hp - 10;
				hero->Hp = hero->Hp - 10;

				gy_status = beforeCtrl;
				break;
			}
		}
		if (level == 2) {
			switch (animGongJi)
			{
			case(0):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\wangzhi\\Battle_FS2.png");
				animGongJi++;
				break;
			case(1):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\wangzhi\\Battle_FS3.png");
				animGongJi++;
				break;
			case(2):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\wangzhi\\Battle_FS4.png");
				animGongJi++;
				break;
			case(3):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\wangzhi\\Battle_FS5.png");
				animGongJi++;
				break;
			case(4):
				mciSendString(L"play res\\death.wav", 0, 0, 0);
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\wangzhi\\Battle_FS1.png");
				animGongJi = 0;
				hp = hp - 10;
				hero->Hp = hero->Hp - 10;

				gy_status = beforeCtrl;
				break;
			}
		}
		if (level == 3) {
			switch (animGongJi)
			{
			case(0):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\qinqi\\Battle_qiang2.png");
				animGongJi++;
				break;
			case(1):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\qinqi\\Battle_qiang3.png");
				animGongJi++;
				break;
			case(2):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\qinqi\\Battle_qiang4.png");
				animGongJi++;
				break;
			case(3):
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\qinqi\\Battle_qiang5.png");
				animGongJi++;
				break;
			case(4):
				mciSendString(L"play res\\daojian.wav", 0, 0, 0);
				Enemy.Destroy();
				Enemy.Load(L"res\\Battle\\Battle\\qinqi\\Battle_qiang1.png");
				animGongJi = 0;
				hp = hp - 10;
				hero->Hp = hero->Hp - 10;

				gy_status = beforeCtrl;
				break;
			}
		}
		
		break;
	}


	/*
	beijing.load();
	Enemy.Load();
	enemyHp.Load();
	Hero.Load();
	CTRL = btmImgList[? ];
	hq.Load();
	mp.Load();
	at.Load();
	*/
	return true;
}

bool ComScene::render(CDC& mDC)
{
	checkKey();
	animation();

	
	draw(mDC);
	return true;
}



bool ComScene::draw(CDC &mDC)
{
	hp_X = hp * 3;
	mp_X = mp * 3;
	enemyhp_X = enemyhp*1.5;
	Back.Draw(mDC.m_hDC, 0, 0, 1000, 550);

	Enemy.Draw(mDC.m_hDC, 0, 0, 1000, 550);
	//enemyHp.Draw();
	Hero.Draw(mDC.m_hDC, 0, 0, 1000, 550);
	//CTRL.draw();
	btmImgList[cs_status]->Draw(mDC.m_hDC, 0, 550, 1000, 200, 0, 0, 1000, 200);
	if(hp>0)
	Hp.Draw(mDC.m_hDC, 651, 588, hp_X, 20, 0, 0, hp_X, 20);
	if (mp >0)
	Mp.Draw(mDC.m_hDC, 651, 638, mp_X, 20, 0, 0, mp_X, 20);

	At.Draw(mDC.m_hDC, 651, 688, 130, 20, 0, 0, 130, 20);
	if(enemyhp>0)
	enemyHp.Draw(mDC.m_hDC, 705, 150, enemyhp_X, 10, 20, 10, enemyhp_X + 20, 23);
	return true;
}
/*
bool ComScene::render(CDC& dc)
{

hp_X = hp * 3;
mp_X = mp * 3;
Back.Draw(dc.m_hDC, 0, 0, 1000, 550, 0, 0, 1000, 550);
//Hero.Draw(dc.m_hDC,0,0,1000,500,0,0,1000,500);

Hero.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);
Enemy.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);
enemyHp.Draw(dc.m_hDC, 705, 150, 150, 10, 10, 10, 160, 20);


for (auto element : nodeList)
{
element->draw(dc);
}

static int flag = 0;
Bottom.Draw(dc.m_hDC, 0, 550, 1000, 200, 0, 0, 1000, 200);
Hp.Draw(dc.m_hDC, 651, 588, hp_X, 20, 0, 0, hp_X, 20);
Mp.Draw(dc.m_hDC, 651, 638, mp_X, 20, 0, 0, mp_X, 20);
if (pic == 1) {
Bottom.Destroy();
Bottom.Load(L"res\\Ctrl_1.png");
if (this->checkKeyDown(KEY_DOWN))
{
pic = 2;
}
if (this->checkKeyDown(KEY_RIGHT))
{
pic = 3;
}
if (this->checkKeyDown(KEY_ENTER)) {
//³·ÍË

}
}
if (pic == 2) {

Bottom.Destroy();
Bottom.Load(L"res\\Ctrl_2.png");
if (this->checkKeyDown(KEY_LEFT))
{
pic = 1;
}
if (this->checkKeyDown(KEY_RIGHT))
{
pic = 3;
}


if (this->checkKeyDown(KEY_ENTER)) {
pic = 7;

}
}

if (pic == 3) {
Bottom.Destroy();
Bottom.Load(L"res\\Ctrl_3.png");
if (this->checkKeyDown(KEY_LEFT))
{
pic = 1;
}
if (this->checkKeyDown(KEY_DOWN))
{
pic = 2;
}

if (this->checkKeyDown(KEY_ENTER)) {

Hero.Destroy();
Hero.Load(L"res\\Battle_GY2.png");
//this->timeDelay();



this->timeLast = this->timeNow();
while (this->timeNow() < this->timeLast + 100)
{
// do nothing;
}



Hero.Destroy();
Hero.Load(L"res\\Battle_GY3.png");


Hero.Destroy();
Hero.Load(L"res\\Battle_GY4.png");

Hero.Destroy();
Hero.Load(L"res\\Battle_GY5.png");
//Hero.Load(L"Battle_GY1.png");

Enemy.Destroy();
Enemy.Load(L"res\\hanfu\\Battle_ZL5.png");

hp = hp - 10;

}

}

if (pic == 4) {
Bottom.Destroy();
Bottom.Load(L"res\\Ctrl_4.png");
if (this->checkKeyDown(KEY_DOWN))
{
pic = 5;
}
if (this->checkKeyDown(KEY_RIGHT))
{
pic = 6;
}

if (this->checkKeyDown(KEY_ENTER)) {
pic = 1;
}
}
if (pic == 5) {
Bottom.Destroy();
Bottom.Load(L"res\\Ctrl_5.png");
if (this->checkKeyDown(KEY_LEFT))
{
pic = 4;
}
if (this->checkKeyDown(KEY_RIGHT))
{
pic = 6;
}

if (this->checkKeyDown(KEY_ENTER)) {
mp = mp - 5;
Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL1.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL2.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

//this->timeDelay();
Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL3.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL4.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL5.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);
//jieng
}
}
if (pic == 6) {
Bottom.Destroy();
Bottom.Load(L"res\\Ctrl_6.png");
if (this->checkKeyDown(KEY_LEFT))
{
pic = 4;
}
if (this->checkKeyDown(KEY_DOWN))
{
pic = 5;
}
if (this->checkKeyDown(KEY_ENTER)) {
//jineng
mp = mp - 5;
Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL21.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL22.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

//this->timeDelay();
Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL23.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL24.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);

Skill.Destroy();
Skill.Load(L"res\\Battle\\guanyu\\SKILL\\SKILL25.png");
Skill.Draw(dc.m_hDC, 0, 0, 1000, 500, 0, 0, 1000, 500);
}
}
if (pic == 7) {
Bottom.Destroy();
Bottom.Load(L"res\\Ctrl_4.png");
if (this->checkKeyDown(KEY_DOWN))
{
pic = 5;
}
if (this->checkKeyDown(KEY_RIGHT))
{
pic = 6;
}

}
return true;
}


*/
