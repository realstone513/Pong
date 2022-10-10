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
	TextObject* clearText;
	Bat* bat;
	Ball* ball;
	RectangleShape ceil;
	list<Block*> blocks;
	list<Block*> hitBlocks;
	Vector2i wSize;
	Vector2f initPos;
	BlockGenerator bg;

	bool ballActive;
	int life;
	int score;
	int curStage;
	int curStageUntouchableCount;
	bool clearGame;

public:
	SceneDev2();
	~SceneDev2();

	virtual void Enter() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
	virtual void Exit() override;
};