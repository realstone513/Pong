#include "Bat.h"
#include "InputManager.h"

Bat::Bat() : speed(0)
{
    shape.setSize({ 100.f, 5.f });
    shape.setPosition(position);
    shape.setFillColor(Color(0, 130, 0, 255));
}

Bat::~Bat()
{
}

Vector2f Bat::GetPosition() const
{
    return position;
}

void Bat::SetPosition(Vector2f position)
{
    this->position = position;
}

float Bat::GetSpeed() const
{
    return speed;
}

void Bat::SetSpeed(float speed)
{
    this->speed = speed;
}

FloatRect Bat::GetBounds() const
{
    return shape.getGlobalBounds();
}

void Bat::Update(float dt)
{
    currentDir.x = InputManager::GetAxisRaw(Axis::Horizontal);

    position += currentDir * speed * dt;
    shape.setPosition(position);

}

void Bat::Draw(RenderWindow& window)
{
    window.draw(shape);
}