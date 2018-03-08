#pragma once


class Scene;


class Node
{
public:
	int chetui;
	/**
	 * \brief ʹ��Ĭ��ֵ����preCreate����
	 */
	Node();
	/**
	 * \brief
	 */
	virtual ~Node();
	/**
	 * \brief ����������Ҫ�����ķ���
	 * \return
	 */
	virtual bool create();
	/**
	 * \brief �����󶨵Ĵ�����
	 * \param aNode ������ײ����һ������
	 * \return һ�ɷ���true�����˷����쳣
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
	 * \param scene Scene ָ��
	 * \param callbk �趨�Ļص�����,һ��Ϊ0
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
	 * \brief �������ĵ������
	 */
	CPoint pos;
	/**
	 * \brief ���͵�����
	 */
	CString cName;
	/**
	* \brief ���������
	*/
	CString oName;
	/**
	 * \brief ������ĵļ�����
	 */
	int dis;
	/**
	* \brief �������Ҫ��ʾͼ��
	*/
	CImage srcImg;
	/**
	 * \brief ͼ���
	 */
	CRect srcRect;
};

