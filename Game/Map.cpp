#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	mapImg = new CImage;
}

bool Map::create(CString& mapName)
{
	cName = L"Map";
	return mapImg->Load(mapName);
}


Map::~Map()
{
}

bool Map::triger(Node& aNode)
{
	return true;
}

bool Map::update()
{
	return true;
}


bool Map::draw(CDC& dc)
{
	return mapImg->Draw(dc.m_hDC, 0, 0, 1000, 750);
}

bool Map::create()
{
	return true;
}

bool Map::update(Scene* scene, int callbk)
{
	return true;
}
