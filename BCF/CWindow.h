#pragma once

#include "stdafx.h"
#include<time.h>


class CCWindow
{
	//==================成员====================
private:
	WNDCLASS    m_wndclass; //窗口类结构体实例
public:
	HWND        m_hwnd;     //窗口句柄
	ATL::CImage      m_img;      //背景图片
	CRect       m_rect;     //窗口户区大小

							//=============窗口创建相关的成员函数=============
public:
	//设计窗口类
	bool InitWndClass(
		HINSTANCE hInstance,    //实例句柄
		WNDPROC   wpWndProc,    //窗口过程
		LPCTSTR   lpWndName,    //窗口名称
		LPCTSTR   lpIconPath);  //图标路径

								//设计窗口类
	bool InitWndClass(WNDCLASS);

	//注册窗口类
	ATOM RegisterWndClass();

	//创建窗口(默认居中)
	void Create(
		LPCTSTR lpClassName,    //窗口类名称
		LPCTSTR lpWndName,  //窗口标题名称
		DWORD   dwStyle,        //窗口风格
		int     nWidth,         //窗口宽度
		int     nHeight);       //窗口高度

								//显示窗口
	void Show(int);

	//一般的消息循环
	int RunMsgLoop();

	//更高效的消息循环
	int RunMsgLoop(void(*Display)(), int);

	//================消息响应函数================
public:
	//注：在这里添加需要响应的消息处理函数的声明
	//处理WM_CREATE消息
	void OnCreate();

	//处理WM_SIZE消息
	void OnSize();

	//处理WM_PAINT消息
	void OnPaint();

	//处理WM_KEYDOWN消息
	void OnKeyDown(WPARAM);

	//处理WM_DESTROY消息
	void OnDestroy();
public:
	//构造函数
	CCWindow(void);
	//析构函数
	~CCWindow(void);
};