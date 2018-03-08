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
	// 重写
		/**
		* \brief srcImg需要先Destory,再Load
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
	// 添加
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