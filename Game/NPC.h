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
	// ��д
	/**
	* \brief ����������Ҫ�����ķ���
	* \return
	*/
	bool create() override;
	/**
	* \brief �����󶨵Ĵ�����
	* \param aNode ������ײ����һ������
	* \return һ�ɷ���true�����˷����쳣
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
	* \param scene Scene ָ��
	* \param callbk �趨�Ļص�����,һ��Ϊ0
	* \return
	*/
	bool update(Scene *scene, int callbk) override;
	/**
	* \brief
	* \return
	*/
	bool animation() override;
	// ʵ��
	bool create(CString &objName, int x, int y,CString &);
public:


	CRect m_heroPos;//true hero
	CRect m_npcPos;    //����npc��λ��  

	CImage npc_kx;   //npc
	CImage m_hero;//true hero
	CImage m_bg;      //����ͼƬ  
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
