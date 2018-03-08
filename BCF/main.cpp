#include "stdafx.h"
#include "main.h"

/*
显示函数：绘制随机位置、大小、颜色的矩形
注：由于调用很频繁，故设为内联函数
*/
inline void Display()
{
	//做响应的操作
}

//
//==============WinMain=======================
//
int WINAPI _tWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//设计窗口类
	CString iconPath = _T("");//图标的路径(这里没有, 需自己设定)
	wnd.InitWndClass(hInstance, WndProc, WNDNAME, iconPath);

	//注册窗口类
	if (!wnd.RegisterWndClass())
	{
		::AfxMessageBox(_T("RegisterWndClass() Failed"));

		return 0;
	}

	DWORD style = WS_OVERLAPPEDWINDOW &
		~(WS_THICKFRAME | WS_MAXIMIZEBOX);

	//创建窗口并居中窗口
	wnd.Create(WNDNAME, WNDNAME, style,
		WNDWIDTH, WNDHEIGHT);

	//显示窗口
	wnd.Show(nShowCmd);

	/*进入消息循环
	1. 使用更好的消息循环 如：wnd.RunMsgLoop(Display, 100)
	2. 使用一般的消息循环 如：wnd.RunMsgLoop()
	*/
	return wnd.RunMsgLoop();
}

//
//================窗口过程：处理消息=================
//
LRESULT CALLBACK WndProc(
	HWND hwnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		wnd.OnCreate(); //窗口建立消息：进行一些初始化操作
		return 0;

	case WM_SIZE:
		wnd.OnSize();   //窗口size消息：获取窗口大小
		return 0;

	case WM_KEYDOWN:    //按键消息
		wnd.OnKeyDown(wParam);
		return 0;

	case WM_PAINT:      //窗口Paint消息：绘制窗口客户区
		wnd.OnPaint();
		return 0;

	case WM_DESTROY:    //窗口销毁消息：释放内存
		wnd.OnDestroy();
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}