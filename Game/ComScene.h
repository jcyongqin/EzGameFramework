#pragma once
#include "Scene.h"
#include "Node.h"
#include "list"
#include <map>
#include <vector>

class Director;


enum CtrlStatus
{
	
	CheTui,
	JinNengNone,
	JinNengGogJi,
	FanHui,
	JinNengChiTu,
	JinNengKuaiDao,
};

enum GuanYuStatus
{
	staandBy = 10,
	useGogJi,
	useChiTu,
	useKuaiDao,
	CheTuiHou,
	beforeCtrl
	
};


class ComScene :
	public Scene
{
public:
	ComScene();
	/**
	* \brief ����Map:Node���ָ�룬���ڶ�����ǰ
	* \return ����Scene���ָ��
	*/


	virtual ~ComScene();
	ComScene* create(Node* hero, Node* enemy, Director * director,int L);
	// ��������

protected:

	// ���
	bool checkKey();

	bool animation();

	bool draw(CDC & mDC);
protected:

private:
	bool render(CDC &mDC) override;
private:

	GuanYuStatus gy_status;
	CtrlStatus cs_status;
	Director *director;
	Scene *oldScene;
	int pic;

	Node *hero; 
	Node *enemy;
	CImage Back;
	CImage Hero;
	CImage enemyHp;
	CImage Enemy;
	std::vector<CImage *> btmImgList;
	CImage Hp;
	CImage Mp;
	CImage At;
	int level;
	int hp;
	int hp_X;
	int mp;
	int mp_X;
	int enemyhp;
	int enemyhp_X;

};
