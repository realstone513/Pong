#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"

using namespace sf;

class Bat
{
private:
	Vector2f position;
	RectangleShape shape;
	float speed;
	Vector2f curDir;

public:
	Bat();
	~Bat();

	float GetSpeed() const;
	void SetSpeed(float speed);

	void SetOrigin(Origins origin);

	Vector2f GetPosition() const;
	void SetPosition(Vector2f position);

	FloatRect GetBounds() const;

	void Update(float dt);
	void Draw(RenderWindow& window);
};