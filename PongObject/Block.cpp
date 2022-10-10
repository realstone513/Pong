#include "Block.h"
#include "../Framework/Utils.h"
#include <iostream>

Block::Block(float x, float y, Vector2f size)
	: centerPos(x + size.x * 0.5f, y + size.y * 0.5f), normalVector(0, 1),
	duration(0.2f), timer(0.0f)
{
	shape.setPosition(x, y);
	shape.setSize(size);
	shape.setFillColor(Color(0, 130, 0, 255));
	shape.setOutlineColor(Color::White);
	shape.setOutlineThickness(2.f);
	theta = Utils::GetAngleBetweenTwoVec({ size.x * 0.5f, size.y * 0.5f }, normalVector);
	hp = 1;
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

void Block::Hit()
{
	hp--;
	active = false;
	timer = duration;
}