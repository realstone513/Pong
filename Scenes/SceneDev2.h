#pragma once
#include "Scene.h"
#include "../GameObject/TextObject.h"
#include "../PongObject/Ball.h"
#include "../PongObject/Bat.h"
#include "../PongObject/Block.h"
#include "../PongObject/BlockGenerator.h"

// Game Scene
class SceneDev2 : public Scene
{
protected:
	TextObject* hud;
	Bat* bat;
	Ball* ball;
	bool ballActive = true;
	int life = 3;
	int score = 0;

public:
	SceneDev2();
	~SceneDev2();

	virtual void Init() override;
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};