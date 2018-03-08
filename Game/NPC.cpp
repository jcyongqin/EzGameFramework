#include "stdafx.h"
#include "NPC.h"
#include "math.h"
#include "Resource1.h"
#include"Scene.h"
#define kx 0

#define least 50
#define most 100

NPC::NPC()
{
}

NPC::NPC(CString& objName, int x, int y)
{
	//create(objName, x, y);
}


NPC::~NPC()
{
}

bool NPC::create()
{
	return true;
}

static CString tem;
bool NPC::create(CString &objName, int x, int y,CString &N)
{
	tem=N;
	status = NPCStatus::noTriger;
	this->cName = L"NPC";
	this->oName = objName;
	this->imgIndex;
	CString fileName = objName;
	pos = POINT({ x, y });

	if (objName == NPC_KONG_XIU)
	{
		if (N != L"0")
		n.Load(N);
		imgList = new CImage[N_NPC_KONG_XIU];
		for (int i = 0; i < N_NPC_KONG_XIU; ++i)
		{
			fileName.Format(NPC_KONG_XIU, i + 1);
			imgList[i].Load(fileName);
		}
	}
	else if (objName == NPC_MENG_TAN)
	{
		if (N != L"0")
		n.Load(N);
		imgList = new CImage[N_NPC_MENG_TAN];
		for (int i = 0; i < N_NPC_MENG_TAN; ++i)
		{
			fileName.Format(NPC_MENG_TAN, i + 1);
			imgList[i].Load(fileName);
		}
	}
	else if (objName == NPC_BIAN_XI)
	{
		if (N != L"0")
		n.Load(N);
		imgList = new CImage[N_NPC_BIAN_XI];
		for (int i = 0; i < N_NPC_BIAN_XI; ++i)
		{
			fileName.Format(NPC_BIAN_XI, i + 1);
			imgList[i].Load(fileName);
		}
	}
	else if (objName == NPC_WANG_ZHI)
	{
		if (N != L"0")
		n.Load(N);
		imgList = new CImage[N_NPC_WANG_ZHI];
		for (int i = 0; i < N_NPC_WANG_ZHI; ++i)
		{
			fileName.Format(NPC_WANG_ZHI, i + 1);
			imgList[i].Load(fileName);
		}
	}
	else if (objName == NPC_QIN_QI)
	{
		if (N != L"0")
		n.Load(N);
		imgList = new CImage[N_NPC_QIN_QI];
		for (int i = 0; i < N_NPC_QIN_QI; ++i)
		{
			fileName.Format(NPC_QIN_QI, i + 1);
			imgList[i].Load(fileName);
		}
	}
	else if (objName == NPC_ZHANG_FEI)
	{
		if (N != L"0")
		n.Load(N);
		imgList = new CImage[N_NPC_ZHANG_FEI];
		for (int i = 0; i < N_NPC_ZHANG_FEI; ++i)
		{
			fileName.Format(NPC_ZHANG_FEI, i + 1);
			imgList[i].Load(fileName);
		}
	}
	
	return true;
}
bool NPC::draw(CDC& pDC)
{
	if (tem != L"0")
	n.Draw(pDC.m_hDC, pos.x+1, pos.y-14, 48, 64, 0, 0, 48, 64);
	if (status == NPCStatus::Triger) {
		dutyProDraw(pDC, 1/*表示第几组图片 第几关*/,status);
		
	}
	
	return true;
}
int i = 0;

bool NPC::update(Scene* scene, int callbk)
{
	static bool flag = true;
	if (!scene->checkKeyDown(KEY_ENTER))
	{
		flag = true;
	}

	if (scene->checkKeyDown(KEY_ENTER) && flag) {
		i++;
		flag = false;

	}
	return true;
}

bool NPC::animation()
{
	return true;
}

bool NPC::triger(Node &node)
{
	if (node.cName == "Hero")
	{
		status = NPCStatus::Triger;
		//dutyProDraw(CDC *pDC, int numOfPic/*表示第几组图片 第几关*/, NPCStatus dutyPub, RECT m_client)
	}
	//if (status == NPCStatus::Triger && node.cName == "Hero")
	//{
	//}
	return true;
}



/*
void NPC::draw(CDC* pDC, RECT m_client) {
	if (status = NPCStatus::Triger)
	{
		dutyProDraw(CDC *pDC, int numOfPic/*表示第几组图片 第几关, NPCStatus dutyPub, RECT m_client);
	}
	int clientWidth = m_client.right - m_client.left;
	int clientHeight = m_client.bottom - m_client.top;
	int dutyY = clientHeight - clientHeight / 3;

	m_hero.Draw(pDC->m_hDC, m_heroPos);
	npc_kx.Draw(pDC->m_hDC, m_npcPos);//npc位置

	dutyProDraw(pDC, 0, status, m_client);//任务过程绘图
	ValidateRect(NULL, &m_client);

}
*/
/*
bool NPC::triger(CDC* pDC, RECT m_npcPos) {//发布任务 改变tri 如果tri 就触发对话框
	int picWidth = m_heroPos.right - m_heroPos.left;
	int picHeight = m_heroPos.bottom - m_heroPos.left;//英雄图片的大小
	if (abs(m_npcPos.left - m_heroPos.left) < picWidth || abs(m_npcPos.top - m_heroPos.top) < picHeight)
		dutyPub = tri;
	else
		dutyPub = notri;


	return true;
}
*/
bool NPC::dutyProDraw(CDC &pDC, int numOfPic/*表示第几组图片 第几关*/, NPCStatus dutyPub) {//任务图片顺序显示


	if (dutyPub == noTriger)
	{
		//m_bg.Draw(pDC.m_hDC, m_client);
		//m_hero.Draw(pDC.m_hDC, m_heroPos);
	}
	//else if (dutyPub == tri)
	//{
	//	//m_duty.Draw(pDC->m_hDC, 0, dutyY, clientWidth, clientHeight / 3);//绘制任务框架
	//}
	else if (dutyPub == Triger) {
		if (i < 5)
		imgList[i].Draw(pDC.m_hDC, 0, 480, 1000, 280);//绘制任务交流图片
	
	}


	return true;
}