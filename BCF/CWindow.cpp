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
*����:��ƴ�����
*@hInstance:    ʵ�����
*@WndProc:      ���ڹ���
*@WndName:      ��������
*@IconPath:     ͼ��·��
-----------------------------*/
bool CCWindow::InitWndClass(HINSTANCE hInstance,//ʵ�����
	WNDPROC WndProc,    //���ڹ���
	LPCTSTR WndName,    //��������
	LPCTSTR IconPath)   //ͼ��·��
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
��ƴ�����
--------------------------------------*/
bool CCWindow::InitWndClass(WNDCLASS wndclass)
{
	m_wndclass = wndclass;

	return true;
}

/*--------------------------------------
ע�ᴰ����
--------------------------------------*/
ATOM CCWindow::RegisterWndClass()
{
	return RegisterClass(&m_wndclass);
}

/*--------------------------------------
��������
--------------------------------------*/
void CCWindow::Create(
	LPCTSTR lpClassName,
	LPCTSTR lpWindowName,
	DWORD dwStyle,
	int nWidth,
	int nHeight)
{
	//��ȡ��Ļ��Ⱥ͸߶�
	int screenW = GetSystemMetrics(SM_CXSCREEN);
	int screenH = GetSystemMetrics(SM_CYSCREEN);

	//������������ʾ����
	m_hwnd = CreateWindow(lpClassName, lpWindowName, dwStyle,
		(screenW - nWidth) / 2, (screenH - nHeight) / 2,
		nWidth, nHeight, NULL, NULL,
		m_wndclass.hInstance, NULL);
}

/*--------------------------------------
��ʾ����
--------------------------------------*/
void CCWindow::Show(int nCmdShow)
{
	ShowWindow(m_hwnd, nCmdShow);
}

//UpdateWindow(...)���´���(����ʡ��)

/*--------------------------------------
һ�����Ϣѭ��
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
��Ϣѭ��(���õ���Ϣѭ��)
PeekMessage()
--------------------------------------*/
int CCWindow::RunMsgLoop(void(*Display)(), int interval)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	//��ȡ���е��˴�ʱ��ʱ��
	int last = GetTickCount();

	//��������˳���Ϣ
	while (msg.message != WM_QUIT)
	{
		//�������Ϣ
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//����, ���е�ʱ��ִ����Ӧ����(������ǻ��ƺ���)
		else
		{
			//������ڿͻ�����С��Ϊ0������ʾ(�п��ܴ���������С��)
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
//                      ��Ϣ��Ӧ����
//----------------------------------------------------------
//ע�������������Ҫ��Ӧ����Ϣ��������ʵ��</hbrush></hicon>

//���ڽ�����Ϣ������һЩ��ʼ������
void CCWindow::OnCreate()
{
	m_img.Load(_T("res/bg.jpg"));

	if (m_img.IsNull())
	{
		AfxMessageBox(_T("����ͼƬ����ʧ��!"));
		exit(0);
	}

	//mciSendString(_T("open"), res\bgm.mp3 alias bgm, 0, 0, 0);
	//mciSendString(_T("play"), bgm repeat, 0, 0, 0);
}

//����size��Ϣ����ȡ���ڴ�С
void CCWindow::OnSize()
{
	::GetClientRect(m_hwnd, m_rect);
}

//����Paint��Ϣ�����ƴ��ڿͻ���
void CCWindow::OnPaint()
{
	CPaintDC dc(CWnd::FromHandle(m_hwnd));

	//���Ʊ���ͼƬ
	dc.SetStretchBltMode(COLORONCOLOR);
	m_img.StretchBlt(dc, 0, 0, m_rect.Width(), m_rect.Height(),
		0, 0, m_img.GetWidth(), m_img.GetHeight(), SRCCOPY);

	//��������
	CFont font;
	font.CreatePointFont(150, _T("΢���ź�"));
	dc.SelectObject(font);

	CString str1 = _T("���Լ�������һ���Ƽ�����Ļ��ᣬ���������Լ����Ҹ�");
	CString str2 = _T("BlueCoder(��С��)");

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(163, 21, 21));
	dc.TextOut(130, 220, str1);

	dc.SetTextColor(RGB(21, 155, 230));
	dc.TextOut(500, 300, str2);
}

//������Ϣ������Esc���˳�����
void CCWindow::OnKeyDown(WPARAM wParam)
{
	if (wParam == VK_ESCAPE)
	{
		DestroyWindow(m_hwnd);
	}
}

//����������Ϣ���ͷ��ڴ�
void CCWindow::OnDestroy()
{
	m_img.Destroy();

	//mciSendString(close bgm, 0, 0, 0);

	PostQuitMessage(0);
}