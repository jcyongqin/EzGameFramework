
// Game.h : Game Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGameApp:
// �йش����ʵ�֣������ Game.cpp
//

class CGameApp : public CWinApp
{
public:
	CGameApp();


// ��д
public:
	BOOL InitInstance() override;
	int ExitInstance() override;

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGameApp theApp;
