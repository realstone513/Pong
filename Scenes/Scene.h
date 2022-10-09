#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "../GameObject/Object.h"
// test code
#include <iostream>

using namespace sf;
using namespace std;

enum class Scenes
{
	Dev1,
    Dev2
};
class Scene
{
protected:
	Scenes type;
    list<Object*> objList;
    list<Object*> uiObjList;

public:
	Scene(Scenes type);
	virtual ~Scene();


    virtual void Init();
	virtual void Enter();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
	virtual void Exit();
};