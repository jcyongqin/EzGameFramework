#pragma once
#include "Node.h"
class Button :
	public Node
{
public:
	Button();
	~Button();
	// ��д
	/**
	 * \brief srcImg��Ҫ��Destory,��Load
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
	// ���


};

