#include "stdafx.h"
#include "CWindow.h"
#include <mciapi.h>
#include "resource.h"


CCWindow::CCWindow(void)
{
}

CCWindow::~CCWindow(void)
{
}

/*------------------------------
*功能:设计窗口类
*@hInstance:    实例句柄
*@WndProc:      窗口过程
*@WndName:      窗口名称
*@IconPath:     图标路径
-----------------------------*/
bool CCWindow::InitWndClass(HINSTANCE hInstance,//实例句柄
	WNDPROC WndProc,    //窗口过程
	LPCTSTR WndName,    //窗口名称
	LPCTSTR IconPath)   //图标路径
{
	ZeroMemory(&m_wndclass, sizeof(WNDCLASS));

	m_wndclass.style = CS_HREDRAW | CS_VREDRAW;
	m_wndclass.lpfnWndProc = WndProc;
	m_wndclass.hInstance = hInstance;
	m_wndclass.cbClsExtra = 0;
	m_wndclass.cbWndExtra = 0;
	m_wndclass.hIcon =
		static_cast<HICON>(LoadImage(NULL, IconPath, IMAGE_ICON,
			0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE));
	m_wndclass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	m_wndclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	m_wndclass.lpszMenuName = NULL;
	m_wndclass.lpszClassName = WndName;

	return true;
}

/*--------------------------------------
设计窗口类
--------------------------------------*/
bool CCWindow::InitWndClass(WNDCLASS wndclass)
{
	m_wndclass = wndclass;

	return true;
}

/*--------------------------------------
注册窗口类
--------------------------------------*/
ATOM CCWindow::RegisterWndClass()
{
	return RegisterClass(&m_wndclass);
}

/*--------------------------------------
创建窗口
--------------------------------------*/
void CCWindow::Create(
	LPCTSTR lpClassName,
	LPCTSTR lpWindowName,
	DWORD dwStyle,
	int nWidth,
	int nHeight)
{
	//获取屏幕宽度和高度
	int screenW = GetSystemMetrics(SM_CXSCREEN);
	int screenH = GetSystemMetrics(SM_CYSCREEN);

	//创建并居中显示窗口
	m_hwnd = CreateWindow(lpClassName, lpWindowName, dwStyle,
		(screenW - nWidth) / 2, (screenH - nHeight) / 2,
		nWidth, nHeight, NULL, NULL,
		m_wndclass.hInstance, NULL);
}

/*--------------------------------------
显示窗口
--------------------------------------*/
void CCWindow::Show(int nCmdShow)
{
	ShowWindow(m_hwnd, nCmdShow);
}

//UpdateWindow(...)更新窗口(可以省略)

/*--------------------------------------
一般的消息循环
GetMessage()
--------------------------------------*/
int CCWindow::RunMsgLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

/*--------------------------------------
消息循环(更好的消息循环)
PeekMessage()
--------------------------------------*/
int CCWindow::RunMsgLoop(void(*Display)(), int interval)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	//获取运行到此处时的时间
	int last = GetTickCount();

	//如果不是退出消息
	while (msg.message != WM_QUIT)
	{
		//如果有消息
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//否则, 空闲的时候执行响应函数(大多数是绘制函数)
		else
		{
			//如果窗口客户区大小不为0就是显示(有可能窗口是在最小化)
			if (m_rect.Width() &&
				m_rect.Height())
			{
				Display();
				Sleep(interval);
			}
		}
	}

	return msg.wParam;
}

//----------------------------------------------------------
//                      消息响应函数
//----------------------------------------------------------
//注：在这里添加需要响应的消息处理函数的实现</hbrush></hicon>

//窗口建立消息：进行一些初始化操作
void CCWindow::OnCreate()
{
	m_img.Load(_T("res/bg.jpg"));

	if (m_img.IsNull())
	{
		AfxMessageBox(_T("背景图片加载失败!"));
		exit(0);
	}

	//mciSendString(_T("open"), res\bgm.mp3 alias bgm, 0, 0, 0);
	//mciSendString(_T("play"), bgm repeat, 0, 0, 0);
}

//窗口size消息：获取窗口大小
void CCWindow::OnSize()
{
	::GetClientRect(m_hwnd, m_rect);
}

//窗口Paint消息：绘制窗口客户区
void CCWindow::OnPaint()
{
	CPaintDC dc(CWnd::FromHandle(m_hwnd));

	//绘制背景图片
	dc.SetStretchBltMode(COLORONCOLOR);
	m_img.StretchBlt(dc, 0, 0, m_rect.Width(), m_rect.Height(),
		0, 0, m_img.GetWidth(), m_img.GetHeight(), SRCCOPY);

	//绘制文字
	CFont font;
	font.CreatePointFont(150, _T("微软雅黑"));
	dc.SelectObject(font);

	CString str1 = _T("给自己的梦想一次破茧而出的机会，创造属于自己的幸福");
	CString str2 = _T("BlueCoder(黎小华)");

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(163, 21, 21));
	dc.TextOut(130, 220, str1);

	dc.SetTextColor(RGB(21, 155, 230));
	dc.TextOut(500, 300, str2);
}

//按键消息：按下Esc键退出程序
void CCWindow::OnKeyDown(WPARAM wParam)
{
	if (wParam == VK_ESCAPE)
	{
		DestroyWindow(m_hwnd);
	}
}

//窗口销毁消息：释放内存
void CCWindow::OnDestroy()
{
	m_img.Destroy();

	//mciSendString(close bgm, 0, 0, 0);

	PostQuitMessage(0);
}