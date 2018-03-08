#pragma once
#include "Node.h"
class Wall :
	public Node
{
public:
	Wall();
	~Wall();
	bool Create(int x,int y);
	bool triger(Node &aNode) override;
};

