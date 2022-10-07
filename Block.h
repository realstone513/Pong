#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Block
{
private:
	RectangleShape shape;
	Vector2f centerPos;
	Vector2f normalVector;
	// normalVector와 중점에서 한 꼭짓점을 이은 벡터의 사이각
	float theta;

public:
	Block(float x, float y, Vector2f size);
	~Block();

	void Update(float dt);
	void Draw(RenderWindow& window);
	void Destroy();

	FloatRect GetBounds() const;
	Vector2f GetCenterPos() const;
	Vector2f GetNormalVector() const;
	float GetTheta() const;
};