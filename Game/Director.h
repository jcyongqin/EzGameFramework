#pragma once

class Scene;
class Node;

class Director
{
public:
	Director();
	bool create();
	bool cSceneB(Node *, Node *,int );
	bool cScene1();
	bool cScene2();
	bool cScene3();
	//bool END();
	~Director();
	Scene *getScene();

	Scene *m_scene;
	Scene *m_sceneOld;
	Scene * changeScene(Node *, Node *, Scene *);
	Scene * changelevel2();
	Scene * changelevel3();
	Scene * end();

};

