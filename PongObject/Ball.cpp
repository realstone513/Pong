#include "Ball.h"
#include <iostream>

Ball::Ball(Vector2f _initPos) : speed(0), initPos(_initPos)
{
	shape.setRadius(10.f);
	shape.setPosition(position);
	shape.setFillColor(Color(200, 50, 00, 255));
}

Ball::~Ball()
{
}

void Ball::Init()
{
	SetOrigin(Origins::BC);
	SetPosition(initPos);
	curDir = { 0, 0 };
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

void Ball::Fire(Vector2f dir, float speed)
{
	curDir = Utils::Normalize(dir);
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

FloatRect Ball::GetBounds() const
{
	return shape.getGlobalBounds();
}

void Ball::OnCollisionTop()
{
	curDir.y = -curDir.y;
 	SetPosition({ position.x, position.y + shape.getRadius() });
	Fire(curDir, speed);
}

void Ball::OnCollisionSides(float width)
{
	curDir.x = -curDir.x;

	if (position.x < width * 0.5f)
		SetPosition({ position.x + shape.getRadius(), position.y });
	else
		SetPosition({ position.x - shape.getRadius(), position.y });
	Fire(curDir, speed);
}

void Ball::OnCollisionBottom()
{
	std::cout << "die" << std::endl;
}

void Ball::OnCollisionBat(Bat* bat)
{
	Vector2f batPosition = bat->GetPosition();
	curDir.x = position.x - batPosition.x;
	curDir.x *= 0.003f;
	curDir.y = position.y - batPosition.y - 1.0f;

	SetPosition({ position.x, position.y - shape.getRadius() });
	Fire(curDir, speed);
}

void Ball::OnCollisionBlock(Block* block)
{
	if (!block->GetActive())
		return;

	Vector2f blockCenterPosition = block->GetCenterPos();
	float curTheta = Utils::GetAngleBetweenTwoVec(
		blockCenterPosition - position, block->GetNormalVector());
	float theta = block->GetTheta();

	if (curTheta < theta)
	{
		cout << "hit top " << block->hp << endl << endl;
		curDir.y = -curDir.y;
	}
	else if (curTheta > 180.f - theta)
	{
		cout << "hit bottom " << block->hp << endl << endl;
		curDir.y = -curDir.y;
	}
	else if (blockCenterPosition.x > position.x)
	{
		cout << "hit left " << block->hp << endl << endl;
		curDir.x = -curDir.x;
	}
	else 
	{
		cout << "hit right " << block->hp << endl << endl;
		curDir.x = -curDir.x;
	}
	Fire(curDir, speed);
}