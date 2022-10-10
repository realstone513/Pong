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
	// normalVector와 중점에서 한 꼭짓점을 이은 벡터의 사이각
	float theta;
	float duration;
	float timer;
	bool untouchable;

	vector<Color> colorArray;

public:
	Block(float x, float y, Vector2f size, int blockType);
	virtual ~Block();
	
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	FloatRect GetBounds() const;
	Vector2f GetCenterPos() const;
	Vector2f GetNormalVector() const;
	float GetTheta() const;
	bool GetUntouchable();
	void Hit();
	int hp;
};