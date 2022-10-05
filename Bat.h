#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f position;
	RectangleShape shape;
	float speed;
	Vector2f currentDir;


public:
	Bat();
	~Bat();

	Vector2f GetPosition() const;
	void SetPosition(Vector2f position);

	float GetSpeed() const;
	void SetSpeed(float speed);


	FloatRect GetBounds() const;

	void Update(float dt);
	void Draw(RenderWindow& window);
};