#include "stdafx.h"
#include "Scene.h"
#include "Node.h"
#include "Map.h"
#include "Hero.h"
#include "NPC.h"
#include "ComScene.h"
#include"Game.h"
// 本体头文件最后include
#include "Director.h"

#include"Enemy.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
Director::Director()
{
	create();
}

int map1[15][20] = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,
1,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,
1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,
0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,
1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,
1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,
1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,
1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,
1,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0,1,1,1,0,
1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,
1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,
1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0
};
//1guan

bool Director::create() {
	cScene1();
	return true;
}
static int le;
bool Director::cSceneB(Node * hero, Node * emeny,int L) {

	PlaySound(
		MAKEINTRESOURCE(IDR_WAVE2),
		GetModuleHandle(NULL),
		SND_RESOURCE | SND_ASYNC | SND_LOOP);
	ComScene * cs = new ComScene;
	
	cs->create(hero, emeny,this,le);
	m_scene = cs;
	return true;
}



bool Director::cScene1()
{
	PlaySound(
		MAKEINTRESOURCE(IDR_WAVE3),
		GetModuleHandle(NULL),
		SND_RESOURCE | SND_ASYNC | SND_LOOP);
	//mciSendString(L"play bjyy.mp3",0,0,0);

		
	le = 1;
	this->m_scene = new Scene;
	//ComScene(*m_scene).create()
	
	auto map = new Map;
	map->create(CString(L"res\\1.jpg"));
	m_scene->create(map,this);
	//
	auto hero = new Hero;
	hero->create( 150, 700);
	m_scene->pushBack(hero);

	//auto enemy1 = new Enemy;
	//enemy1->create(CString(L"res\\Battle\\Battle\\kongxiu\\ENE_KX.png"), 150, 550);
	//m_scene->pushBack(enemy1);

	//auto npc2 = new NPC;
	//npc2->create(CString(NPC_BIAN_XI),350,300);
	//m_scene->pushBack(npc2);
	auto enemy1 = new Enemy;
	enemy1->create(CString(L"res\\Battle\\Battle\\bianxi\\ENE_CAO.png"), 530, 30);
	m_scene->pushBack(enemy1);

	auto enemy2 = new Enemy;
	enemy2->create(CString(L"res\\Battle\\Battle\\bubing\\ENE_BU.png"), 350, 300);
	m_scene->pushBack(enemy2);

	//auto npc3 = new NPC;
	//npc3->create(CString("res\\Battle\\Battle\\kongxiu\\ENE_KX.png"), 800, 650);
	//m_scene->pushBack(npc3);
	auto enemy3 = new Enemy;
	enemy3->create(CString(L"res\\Battle\\Battle\\hanfu\\ENE_ZL.png"), 800, 650);
	m_scene->pushBack(enemy3);


	auto npc1 = new NPC;
	npc1->create(CString(NPC_KONG_XIU), 150, 550,CString(L"res\\Battle\\Battle\\kongxiu\\ENE_KX.png"));
	m_scene->pushBack(npc1);

	return true;
}


//2guan

bool Director::cScene2()
{
	PlaySound(
		MAKEINTRESOURCE(IDR_WAVE1),
		GetModuleHandle(NULL),
		SND_RESOURCE | SND_ASYNC | SND_LOOP);
	this->m_scene = new Scene;
	//ComScene(*m_scene).create()
	auto map = new Map;
	map->create(CString(L"res\\2.jpg"));
	m_scene->create(map,this);
	//
	auto hero = new Hero;
	hero->create(150, 700);
	m_scene->pushBack(hero);
	
		
	//auto enemy1 = new Enemy;
	//enemy1->create(CString(L"res\\Battle\\Battle\\kongxiu\\ENE_KX.png"), 150, 550);
	//m_scene->pushBack(enemy1);

	//auto npc2 = new NPC;
	//npc2->create(CString(NPC_BIAN_XI),350,300);
	//m_scene->pushBack(npc2);
auto enemy2 = new Enemy;
enemy2->create(CString(L"res\\Battle\\Battle\\bubing\\ENE_BU.png"), 300, 300);
m_scene->pushBack(enemy2);


auto enemy3 = new Enemy;
enemy3->create(CString(L"res\\Battle\\Battle\\wangzhi\\ENE_FS.png"), 700, 50);
m_scene->pushBack(enemy3);

auto enemy4 = new Enemy;
enemy4->create(CString(L"res\\Battle\\Battle\\gongbing\\ENE_GONG.png"), 450, 500);
m_scene->pushBack(enemy4);

auto npc1 = new NPC;
npc1->create(CString(NPC_MENG_TAN), 200, 600, CString(L"res\\Battle\\Battle\\mengtan\\ENE_dao2.png"));
m_scene->pushBack(npc1);
return true;
}

bool Director::cScene3()
{
	//mciSendString(L"play res\\long.wma", 0, 0, 0);
	/*
	PlaySound(
		MAKEINTRESOURCE(IDR_WAVE1),
		GetModuleHandle(NULL),
		SND_RESOURCE | SND_ASYNC | SND_LOOP);
		*/
	this->m_scene = new Scene;
	auto map = new Map;
	map->create(CString(L"res\\4.jpg"));
	m_scene->create(map, this);
	//
	auto hero = new Hero;
	hero->create(50, 700);
	m_scene->pushBack(hero);

	auto enemy1 = new Enemy;
	enemy1->create(CString(L"res\\Battle\\Battle\\gongbing\\ENE_GONG.png"),700, 100);
	m_scene->pushBack(enemy1);

	auto enemy2 = new Enemy;
	enemy2->create(CString(L"res\\Battle\\Battle\\bubing\\ENE_BU.png"), 300, 300);
	m_scene->pushBack(enemy2);


	auto enemy3 = new Enemy;
	enemy3->create(CString(L"res\\Battle\\Battle\\NPC\\LIU_BEI.png"), 300, 50);
	m_scene->pushBack(enemy3);

	auto enemy4 = new Enemy;
	enemy4->create(CString(L"res\\Battle\\Battle\\gongbing\\ENE_GONG.png"), 450, 400);
	m_scene->pushBack(enemy4);

	auto npc1 = new NPC;
	//150, 600
	npc1->create(CString(NPC_QIN_QI), 50, 700, CString(L"0"));
	m_scene->pushBack(npc1);
	return true;
}

Director::~Director()
{
}

Scene *Director::getScene()
{
	if (m_scene == nullptr)
	{
		throw(L"Scenc not created");
	}
	return m_scene;
}

Scene * Director::changeScene(Node * hero,Node * enemy,Scene * oldScene)
{
	if (hero == nullptr&&enemy == nullptr&&oldScene == nullptr) {
		if (le == 1){
			PlaySound(
				MAKEINTRESOURCE(IDR_WAVE3),
				GetModuleHandle(NULL),
				SND_RESOURCE | SND_ASYNC | SND_LOOP);
		}
		if (le == 2){
			PlaySound(
				MAKEINTRESOURCE(IDR_WAVE1),
				GetModuleHandle(NULL),
				SND_RESOURCE | SND_ASYNC | SND_LOOP);
		}
		if (le == 3){
			PlaySound(
				MAKEINTRESOURCE(IDR_WAVE1),
				GetModuleHandle(NULL),
				SND_RESOURCE | SND_ASYNC | SND_LOOP);
		}
		m_scene = m_sceneOld;
		m_scene->create();

		return nullptr;
	}

	m_sceneOld = m_scene;
	cSceneB(hero, enemy,le);

	return m_scene;
}

Scene * Director::changelevel2() 
{
	le = 2;
	m_sceneOld = m_scene;
	cScene2();
	return nullptr;
	//cScene2();
}

Scene * Director::changelevel3()
{
	le = 3;
	m_sceneOld = m_scene;
	cScene3();
	return nullptr;
	//cScene2();
}

Scene * Director::end()
{
	this->m_scene = new Scene;
	le = 4;
	auto map = new Map;
	map->create(CString(L"res\\Main_Back.png"));
	m_scene->create(map, this);
	return nullptr;
}

