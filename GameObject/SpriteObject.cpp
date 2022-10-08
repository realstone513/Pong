#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
}

SpriteObject::~SpriteObject()
{
}

void SpriteObject::Init()
{
}

void SpriteObject::Update(float dt)
{
    sprite.setPosition(position);
}

void SpriteObject::Draw(RenderWindow& window)
{
    window.draw(sprite);
}

void SpriteObject::SetTexture(Texture& tex)
{
    sprite.setTexture(tex);
}

void SpriteObject::SetOrigin(Origins origin)
{
    Utils::SetOrigin(sprite, origin);
}