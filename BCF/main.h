/***
*
*   Main.h
*   ���������������ͷ�ļ����궨�塢������
*
***/

#pragma once
#include "CWindow.h"


#define WNDNAME _T("VC++��Ϸ����") //��������
#define WNDWIDTH 800 //���ڿ��
#define WNDHEIGHT 600 //���ڸ߶�

//���ڹ�������ȫ�ֶ���
CCWindow wnd;

//���ڹ���
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);