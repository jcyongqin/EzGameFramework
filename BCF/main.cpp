#include "stdafx.h"
#include "main.h"

/*
��ʾ�������������λ�á���С����ɫ�ľ���
ע�����ڵ��ú�Ƶ��������Ϊ��������
*/
inline void Display()
{
	//����Ӧ�Ĳ���
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
	//��ƴ�����
	CString iconPath = _T("");//ͼ���·��(����û��, ���Լ��趨)
	wnd.InitWndClass(hInstance, WndProc, WNDNAME, iconPath);

	//ע�ᴰ����
	if (!wnd.RegisterWndClass())
	{
		::AfxMessageBox(_T("RegisterWndClass() Failed"));

		return 0;
	}

	DWORD style = WS_OVERLAPPEDWINDOW &
		~(WS_THICKFRAME | WS_MAXIMIZEBOX);

	//�������ڲ����д���
	wnd.Create(WNDNAME, WNDNAME, style,
		WNDWIDTH, WNDHEIGHT);

	//��ʾ����
	wnd.Show(nShowCmd);

	/*������Ϣѭ��
	1. ʹ�ø��õ���Ϣѭ�� �磺wnd.RunMsgLoop(Display, 100)
	2. ʹ��һ�����Ϣѭ�� �磺wnd.RunMsgLoop()
	*/
	return wnd.RunMsgLoop();
}

//
//================���ڹ��̣�������Ϣ=================
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
		wnd.OnCreate(); //���ڽ�����Ϣ������һЩ��ʼ������
		return 0;

	case WM_SIZE:
		wnd.OnSize();   //����size��Ϣ����ȡ���ڴ�С
		return 0;

	case WM_KEYDOWN:    //������Ϣ
		wnd.OnKeyDown(wParam);
		return 0;

	case WM_PAINT:      //����Paint��Ϣ�����ƴ��ڿͻ���
		wnd.OnPaint();
		return 0;

	case WM_DESTROY:    //����������Ϣ���ͷ��ڴ�
		wnd.OnDestroy();
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}