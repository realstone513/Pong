#pragma once
#include <SFML/Graphics.hpp>
#include "../GameObject/Object.h"

using namespace sf;

class Block : public Object
{
private:
	RectangleShape shape;
	Vector2f centerPos;
	Vector2f normalVector;
	// normalVector�� �������� �� �������� ���� ������ ���̰�
	float theta;

public:
	Block(float x, float y, Vector2f size);
	virtual ~Block();
	
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	FloatRect GetBounds() const;
	Vector2f GetCenterPos() const;
	Vector2f GetNormalVector() const;
	float GetTheta() const;
};