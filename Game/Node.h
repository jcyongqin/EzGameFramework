#pragma once


class Scene;


class Node
{
public:
	int chetui;
	/**
	 * \brief 使用默认值调用preCreate方法
	 */
	Node();
	/**
	 * \brief
	 */
	virtual ~Node();
	/**
	 * \brief 必须重载需要参数的方法
	 * \return
	 */
	virtual bool create();
	/**
	 * \brief 与对象绑定的触发器
	 * \param aNode 与它碰撞的另一个对象
	 * \return 一律返回true，除了发生异常
	 */
	virtual	bool triger(Node &aNode);
	/**
	 * \brief
	 * \param dc
	 * \return
	 */
	virtual	bool draw(CDC &dc);
	/**
	 * \brief
	 * \param scene Scene 指针
	 * \param callbk 设定的回调参数,一般为0
	 * \return
	 */
	virtual bool update(Scene *scene, int callbk);
	/**
	 * \brief
	 * \return
	 */
	virtual bool animation();
public:
	int Hp;
	int Mp;
	enum  S s;

	/**
	 * \brief 结点的中心点的坐标
	 */
	CPoint pos;
	/**
	 * \brief 类型的名字
	 */
	CString cName;
	/**
	* \brief 对象的名字
	*/
	CString oName;
	/**
	 * \brief 对象关心的检测距离
	 */
	int dis;
	/**
	* \brief 对象的主要显示图像
	*/
	CImage srcImg;
	/**
	 * \brief 图像的
	 */
	CRect srcRect;
};

