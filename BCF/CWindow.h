#pragma once

#include "stdafx.h"
#include<time.h>


class CCWindow
{
	//==================��Ա====================
private:
	WNDCLASS    m_wndclass; //������ṹ��ʵ��
public:
	HWND        m_hwnd;     //���ھ��
	ATL::CImage      m_img;      //����ͼƬ
	CRect       m_rect;     //���ڻ�����С

							//=============���ڴ�����صĳ�Ա����=============
public:
	//��ƴ�����
	bool InitWndClass(
		HINSTANCE hInstance,    //ʵ�����
		WNDPROC   wpWndProc,    //���ڹ���
		LPCTSTR   lpWndName,    //��������
		LPCTSTR   lpIconPath);  //ͼ��·��

								//��ƴ�����
	bool InitWndClass(WNDCLASS);

	//ע�ᴰ����
	ATOM RegisterWndClass();

	//��������(Ĭ�Ͼ���)
	void Create(
		LPCTSTR lpClassName,    //����������
		LPCTSTR lpWndName,  //���ڱ�������
		DWORD   dwStyle,        //���ڷ��
		int     nWidth,         //���ڿ��
		int     nHeight);       //���ڸ߶�

								//��ʾ����
	void Show(int);

	//һ�����Ϣѭ��
	int RunMsgLoop();

	//����Ч����Ϣѭ��
	int RunMsgLoop(void(*Display)(), int);

	//================��Ϣ��Ӧ����================
public:
	//ע�������������Ҫ��Ӧ����Ϣ������������
	//����WM_CREATE��Ϣ
	void OnCreate();

	//����WM_SIZE��Ϣ
	void OnSize();

	//����WM_PAINT��Ϣ
	void OnPaint();

	//����WM_KEYDOWN��Ϣ
	void OnKeyDown(WPARAM);

	//����WM_DESTROY��Ϣ
	void OnDestroy();
public:
	//���캯��
	CCWindow(void);
	//��������
	~CCWindow(void);
};