#include "Ball.h"

Ball::Ball() : speed(0)
{ 
	shape.setRadius(10.f);
	shape.setPosition(position);
}

void Ball::Fire(Vector2f dir, float speed)
{
	currentDir = dir;
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

void Ball::Draw(RenderWindow& window)
{
	window.draw(shape);
}

void Ball::Update(float dt)
{
	position += currentDir * speed * dt;
	shape.setPosition(position);
}

Ball::~Ball()
{
}