#pragma once
#include "Resource1.h"

enum HeroStatus
{
	// վ��״̬
	standUp,
	cantGoDown,
	cantGoUp,
	cantGoLeft,
	cantGoRight,
	// ����״̬
	goDown,
	goUp,
	goLeft,
	goRight,

};


class Hero :
	public Node
{
public:
	Hero();
	~Hero();
	
// ��д
	/**
	* \brief srcImg��Ҫ��Destory,��Load
	* \return
	*/
	bool create() override;
	bool create(int ,int);
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

// ���
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
	bool walk();

public:
	HeroStatus status;

};

