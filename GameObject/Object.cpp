#include "Object.h"

int Object::objCount = 1;

Object::Object()
{
    id = objCount++;
    Init();
}

Object::~Object()
{
    Release();
}

int Object::GetObjectID()
{
    return id;
}

void Object::SetActive(bool active)
{
    enabled = active;
}

bool Object::GetActive() const
{
    return enabled;
}

void Object::SetPosition(Vector2f pos)
{
    position = pos;
}

Vector2f Object::GetPosition() const
{
    return position;
}

void Object::Init()
{
}

void Object::Release()
{
}

void Object::Update(float dt)
{
}

void Object::Draw(RenderWindow& window)
{
}

void Object::Translate(Vector2f delta)
{
    SetPosition(position + delta);
}