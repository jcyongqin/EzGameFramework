#include "stdafx.h"
#include "Wall.h"


Wall::Wall()
{
	
}



Wall::~Wall()
{

}

bool Wall::Create(int x, int y)
{
	cName = L"Wall";
	pos.x = x;
	pos.y = y;
	return false;
}

bool Wall::triger(Node& aNode)
{
	return true;
}

