#include "Block.h"
#include "../Framework/Utils.h"
#include <iostream>

Block::Block(float x, float y, Vector2f size, int blockType)
	: centerPos(x + size.x * 0.5f, y + size.y * 0.5f), normalVector(0, 1),
	duration(0.15f), timer(0.0f), untouchable(false)
{
	colorArray.push_back(Color(102, 102, 102, 255));
	colorArray.push_back(Color(0, 204, 0, 255));
	colorArray.push_back(Color(0, 0, 204, 255));
	colorArray.push_back(Color(102, 51, 204, 255));
	colorArray.push_back(Color(255, 153, 0, 255));
	colorArray.push_back(Color(255, 51, 0, 255));
	colorArray.push_back(Color(0, 0, 0, 255));

	hp = blockType;
	if (blockType == 6)
		untouchable = true;
	shape.setPosition(x, y);
	shape.setSize(size);
	shape.setFillColor(colorArray[hp]);
	shape.setOutlineColor(Color::White);
	shape.setOutlineThickness(2.f);
	theta = Utils::GetAngleBetweenTwoVec({ size.x * 0.5f, size.y * 0.5f }, normalVector);
}

Block::~Block()
{
}

void Block::Update(float dt)
{
	if (timer > 0.f)
	{
		timer -= dt;
		if (timer < 0.f)
			active = true;
	}
}

void Block::Draw(RenderWindow& window)
{
	window.draw(shape);
}

FloatRect Block::GetBounds() const
{
	return shape.getGlobalBounds();
}

Vector2f Block::GetCenterPos() const
{
	return centerPos;
}

Vector2f Block::GetNormalVector() const
{
	return normalVector;
}

float Block::GetTheta() const
{
	return theta;
}

bool Block::GetUntouchable()
{
	return untouchable;
}

void Block::Hit()
{
	if (untouchable)
		return;
	
	hp--;
	shape.setFillColor(colorArray[hp]);
	if (hp == 0)
		shape.setOutlineColor(Color::Black);
	active = false;
	timer = duration;
}