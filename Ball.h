#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"

using namespace sf;
using namespace std;

class Ball
{
private:
	CircleShape shape;
	Vector2f position;
	float speed;
	Vector2f curDir;

public:
	Ball();
	~Ball();

	void Fire(Vector2f dir, float speed);

	void SetSpeed(float speed);
	float GetSpeed() const;

	void SetOrigin(Origins origin);

	void SetPosition(Vector2f position);
	Vector2f GetPosition() const;

	FloatRect GetBounds() const;

	void OnCollisionTop();
	void OnCollisionSides(float width);
	void OnCollisionBottom();
	void OnCollisionBat();

	void Update(float dt);
	void Draw(RenderWindow& window);
};