#pragma once
#include "Node.h"
#include "Scene.h"

class Map :
	public Node
{
public:
	Map();
	~Map();
	bool create(CString &mapName);

	bool draw(CDC &dc)override;
	bool create() override;

	/**
	* \brief 与对象绑定的触发器
	* \param aNode 与它碰撞的另一个对象
	* \return 一律返回true，除了发生异常
	*/
	bool triger(Node &aNode) override;
	bool update();
	/**
	 * \brief
	 * \param dc
	 * \return
	 */
	bool update(Scene* scene,int callbk)override;
public:
private:
	CImage *mapImg;
};

