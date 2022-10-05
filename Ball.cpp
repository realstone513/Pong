#include "Ball.h"
#include <iostream>

Ball::Ball()
	: speed(0), isCollision(true)
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

void Ball::OnCollision()
{

}

void Ball::OnCollisionTop()
{
	curDir.y *= -1;
	SetisCollision(true);
	std::cout << "top" << std::endl;
}

void Ball::OnCollisionSides()
{
	curDir.x *= -1;
	SetisCollision(true);
	std::cout << "side" << std::endl;
}

void Ball::OnCollisionBottom()
{
	std::cout << "die" << std::endl;
}

void Ball::OnCollisionBat()
{
	std::cout << "bat" << std::endl;
	curDir.y *= -1;
	SetisCollision(true);
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

void Ball::SetisCollision(bool col)
{
	isCollision = col;
}

bool Ball::GetisCollision()
{
	return isCollision;
}
