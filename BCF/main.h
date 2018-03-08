/***
*
*   Main.h
*   主程序所需包含的头文件、宏定义、声明等
*
***/

#pragma once
#include "CWindow.h"


#define WNDNAME _T("VC++游戏开发") //窗口名称
#define WNDWIDTH 800 //窗口宽度
#define WNDHEIGHT 600 //窗口高度

//窗口关联对象：全局对象
CCWindow wnd;

//窗口过程
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);