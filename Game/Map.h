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
	* \brief �����󶨵Ĵ�����
	* \param aNode ������ײ����һ������
	* \return һ�ɷ���true�����˷����쳣
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

