#include "stdafx.h"
#include "Start.h"
#include"Director.h"
#include "Resource1.h"

Start::Start()
{
}


Start::~Start()
{
}

bool Start::render(CDC & dc)
{
	CImage img;
	img.Load(L"res\\2.jpg");
	img.Draw(dc.m_hDC,0,0,1000,750);
	if (this->checkKeyDown(KEY_ENTER)) {
		director->cScene1();
	}
	return false;
}

bool Start::create(Director *doc)
{
	this->director = doc;
	return false;
}
