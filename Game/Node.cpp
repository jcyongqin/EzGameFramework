#include "stdafx.h"
#include "Node.h"
#include "Resource1.h"



Node::Node()
{
	Node::create();
}


Node::~Node()
{
}

bool Node::create()
{
	pos = POINT({ 500,400 });
	cName = L"Node";
	oName = L"node";
	dis = 50;
	srcImg.Load(BMP_NODE);
	srcRect = RECT({ 0,0,50,50 });
	return true;
}

bool Node::triger(Node& aNode)
{
	return true;
}

bool Node::draw(CDC& dc)
{
	return true;
}

bool Node::update(Scene* scene, int callbk)
{
	return true;
}

bool Node::animation()
{
	return true;
}


