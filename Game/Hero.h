#pragma once
#include "Resource1.h"

enum HeroStatus
{
	// 站立状态
	standUp,
	cantGoDown,
	cantGoUp,
	cantGoLeft,
	cantGoRight,
	// 行走状态
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
	
// 重写
	/**
	* \brief srcImg需要先Destory,再Load
	* \return
	*/
	bool create() override;
	bool create(int ,int);
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

// 添加
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
	bool walk();

public:
	HeroStatus status;

};

