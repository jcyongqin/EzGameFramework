
// Game.h : Game 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CGameApp:
// 有关此类的实现，请参阅 Game.cpp
//

class CGameApp : public CWinApp
{
public:
	CGameApp();


// 重写
public:
	BOOL InitInstance() override;
	int ExitInstance() override;

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGameApp theApp;
