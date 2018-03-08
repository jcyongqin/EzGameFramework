#pragma once
#include "Scene.h"

class Director;
class Start :
	public Scene
{
public:
	Start();
	~Start();
	bool render(CDC&dc) override;
	bool create(Director *);
	 
};

