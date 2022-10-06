#include "Ball.h"
#include <iostream>

Ball::Ball()
	: speed(0)
{
	shape.setRadius(10.f);
	shape.setPosition(position);
}

Ball::~Ball()
{
}

void Ball::Fire(Vector2f dir, float speed)
{
	curDir = dir;
	this->speed = speed;
}

void Ball::SetSpeed(float speed)
{
	this->speed = speed;
}

float Ball::GetSpeed() const
{
	return speed;
}

void Ball::SetOrigin(Origins origin)
{
	Utils::SetOrigin(shape, origin);
}

void Ball::SetPosition(Vector2f position)
{
	this->position = position;
}

Vector2f Ball::GetPosition() const
{
	return position;
}

FloatRect Ball::GetBounds() const
{
	return shape.getGlobalBounds();
}

void Ball::OnCollisionTop()
{
	curDir.y = -curDir.y;
	SetPosition({ position.x, position.y + shape.getRadius() });
}

void Ball::OnCollisionSides(float width)
{
	curDir.x = -curDir.x;
	if (position.x < width * 0.5f)
		SetPosition({ position.x + shape.getRadius(), position.y });
	else
		SetPosition({ position.x - shape.getRadius(), position.y });
}

void Ball::OnCollisionBottom()
{
	std::cout << "die" << std::endl;
}

void Ball::OnCollisionBat()
{
	curDir.y = -curDir.y;
	SetPosition({ position.x, position.y - shape.getRadius() });
}

void Ball::OnCollisionBlock(Block* block)
{
//	curDir.y = -curDir.y;
}

void Ball::Update(float dt)
{
	position += curDir * speed * dt;
	shape.setPosition(position);
}

void Ball::Draw(RenderWindow& window)
{
	window.draw(shape);
}