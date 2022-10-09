#pragma once
#include "Scene.h"
#include "../GameObject/TextObject.h"

// Title & Menu
class SceneDev1 : public Scene
{
protected:
	TextObject* title;
	TextObject* titleShadow;

public:
	SceneDev1();
	~SceneDev1();

	virtual void Enter() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
	virtual void Exit() override;
};