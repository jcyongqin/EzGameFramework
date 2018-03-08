
// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
#include "Game.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "ChildView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	director = new Director;
}

CChildView::~CChildView()
{

}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()



// CChildView ��Ϣ�������

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	// TODO: �ڴ˴������Ϣ����������

	Scene *scene = director->getScene();
	scene->run(this);
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	//PlaySound(
		//MAKEINTRESOURCE(IDR_WAVE1),
		//GetModuleHandle(NULL),
		//SND_RESOURCE | SND_ASYNC);
	SetTimer(60, 144, nullptr);		//60 Ϊ��ʱ��ID
	return 0;
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//60 Ϊ��ʱ��ID
	if (nIDEvent == 60)
	{
		Scene *scene = director->getScene();
		scene->run(this);
	}
	CWnd::OnTimer(nIDEvent);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	Scene *scene=director->getScene();
	scene->onKeyDown(nChar);
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	Scene *scene = director->getScene();
	scene->onKeyUp(nChar);
	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}
