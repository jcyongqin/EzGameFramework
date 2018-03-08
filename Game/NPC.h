#pragma once
#include "Node.h"
enum NPCStatus
{
	noTriger,
	Triger,
};


class NPC
	:public Node
{
public:
	NPC();
	NPC(CString &objName, int x, int y);
	~NPC();
	// 重写
	/**
	* \brief 必须重载需要参数的方法
	* \return
	*/
	bool create() override;
	/**
	* \brief 与对象绑定的触发器
	* \param aNode 与它碰撞的另一个对象
	* \return 一律返回true，除了发生异常
	*/
	bool triger(Node &aNode) override;
	/**
	* \brief
	* \param dc
	* \return
	*/
	bool draw(CDC &dc) override;
	/**
	* \brief
	* \param scene Scene 指针
	* \param callbk 设定的回调参数,一般为0
	* \return
	*/
	bool update(Scene *scene, int callbk) override;
	/**
	* \brief
	* \return
	*/
	bool animation() override;
	// 实现
	bool create(CString &objName, int x, int y,CString &);
public:


	CRect m_heroPos;//true hero
	CRect m_npcPos;    //保存npc的位置  

	CImage npc_kx;   //npc
	CImage m_hero;//true hero
	CImage m_bg;      //背景图片  
	CImage m_duty;

	CImage dutyPic[4][4];

	CBitmap *bitmap[4][4];
	CImage n;
	CDC *mdc;

	int dir, index;


	//void draw(CDC* pDC, RECT m_client);
	//bool triger(CDC* pDC, RECT m_heroPos);//true hero
										  //bool dutyProLoad(CDC *pDC, enum npcState dutyPub);
	bool dutyProDraw(CDC &pDC, int numOfPic,  NPCStatus dutyPub);
private:

	NPCStatus status;
	CImage *imgList;
	int imgIndex;
	CImage talk;
	
};
