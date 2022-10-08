#include "Bat.h"
#include "../Framework/InputManager.h"

Bat::Bat() : speed(0)
{
    shape.setSize({ 1000.f, 5.f });
    shape.setPosition(position);
    shape.setFillColor(Color(200, 0, 0, 255));
}

Bat::~Bat()
{
}

float Bat::GetSpeed() const
{
    return speed;
}

void Bat::SetSpeed(float speed)
{
    this->speed = speed;
}

void Bat::SetOrigin(Origins origin)
{
    Utils::SetOrigin(shape, origin);
}

FloatRect Bat::GetBounds() const
{
    return shape.getGlobalBounds();
}

void Bat::Update(float dt)
{
    curDir.x = InputManager::GetAxisRaw(Axis::Horizontal);

    position += curDir * speed * dt;
    shape.setPosition(position);
}

void Bat::Draw(RenderWindow& window)
{
    window.draw(shape);
}