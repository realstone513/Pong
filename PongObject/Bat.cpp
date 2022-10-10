#include "Bat.h"
#include "../Framework/InputManager.h"

Bat::Bat(Vector2f _initPos) : speed(1000), initPos(_initPos)
{
    shape.setSize({ 150.f, 10.f });
    shape.setPosition(position);
    shape.setFillColor(Color(120, 120, 120, 255));
}

Bat::~Bat()
{
}

void Bat::Init()
{
    SetOrigin(Origins::TC);
    SetPosition(initPos);
    SetSpeed(1000.f);
}

void Bat::Update(float dt)
{
    curDir.x = InputManager::GetAxisRaw(Axis::Horizontal);

    if (!(position.x < 0 && curDir.x == -1) &&
        !(position.x > initPos.x * 2 && curDir.x == 1))
        position += curDir * speed * dt;
    shape.setPosition(position);
}

void Bat::Draw(RenderWindow& window)
{
    window.draw(shape);
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