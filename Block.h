#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Block
{
private:
	RectangleShape shape;

public:
	Block(float x, float y);
	~Block();

	void Update(float dt);
	void Draw(RenderWindow& window);
	void Destroy();

	FloatRect GetBounds() const;
};