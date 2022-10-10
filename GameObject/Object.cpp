#include "Object.h"

int Object::objCount = 1;

Object::Object(const Object& ref)
{
}

Object& Object::operator=(const Object& ref)
{
    return *this;
}

Object::Object()
    : active(true)
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
    this->active = active;
}

bool Object::GetActive() const
{
    return active;
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
}