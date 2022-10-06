#include "Block.h"

Block::Block(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize(Vector2f( { 36, 30 }));
	shape.setFillColor(Color::Blue);
	shape.setOutlineColor(Color::White);
	shape.setOutlineThickness(2.f);
}

Block::~Block()
{
}

void Block::Update(float dt)
{

}

void Block::Draw(RenderWindow& window)
{
	window.draw(shape);
}

void Block::Destroy()
{
}

FloatRect Block::GetBounds() const
{
	return shape.getGlobalBounds();
}
