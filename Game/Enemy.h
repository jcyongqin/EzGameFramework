#pragma once
#include "Node.h"



enum S {
	nofight,
	fight,
	afterfight
};
class Enemy :
	public Node
{
public:
	
	Enemy();
	~Enemy();
	S s;
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
		/**
		 * \brief
		 * \return
		 */
	bool create(CString& Name, int x, int y);
	/**
	 * \brief
	 * \return
	 */
	bool animation();
public:
	/**
	 * \brief
	 */

	/**
	 * \brief
	 */

	/**
	 * \brief
	 */
	
	/**
	 * \brief
	 */
	CPoint srcPoint;
	Node *m_Hero;
};