#include "Ball.h"
#include <iostream>

Ball::Ball(Vector2f _initPos) : speed(0), initPos(_initPos)
{
	shape.setRadius(10.f);
	shape.setPosition(position);
}

Ball::~Ball()
{
}

void Ball::Init()
{
	SetOrigin(Origins::BC);
	SetPosition(initPos);
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
	Vector2f blockCenterPosition = block->GetCenterPos();

	/*cout << "Ball position: (" << position.x << ", " << position.y << ")" << endl;
	cout << "Block position: (" << blockCenterPosition.x <<
		", " << blockCenterPosition.y << ")" << endl;*/
	float curTheta = Utils::GetAngleBetweenTwoVec(
		blockCenterPosition - position, block->GetNormalVector());

	float theta = block->GetTheta();
	//cout << curTheta << " " << theta << endl;

	if (curTheta < theta)
	{
		cout << "hit top" << endl << endl;
		curDir.y = -curDir.y;
		//SetPosition({ position.x, position.y - shape.getRadius() });
	}
	else if (curTheta > 180.f - theta)
	{
		cout << "hit bottom" << endl << endl;
		curDir.y = -curDir.y;
		//SetPosition({ position.x, position.y + shape.getRadius() });
	}
	else if (blockCenterPosition.x > position.x)
	{
		cout << "hit left" << endl << endl;
		curDir.x = -curDir.x;
		//SetPosition({ position.x - shape.getRadius(), position.y });
	}
	else 
	{
		cout << "hit right" << endl << endl;
		curDir.x = -curDir.x;
		//SetPosition({ position.x + shape.getRadius(), position.y });
	}
}