#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	CircleShape shape;
	Vector2f position;
	float speed;
	Vector2f currentDir;


public:
	Ball();
	void Fire(Vector2f dir, float speed);
	void SetSpeed(float speed);
	float GetSpeed() const;
	void SetPosition(Vector2f position);
	Vector2f GetPosition() const;
	FloatRect GetBounds() const;
	void Draw(RenderWindow& window);
	void Update(float dt);
	~Ball();
};