#include "TextObject.h"

TextObject::TextObject(Font& font, string textString,
    float sizeX, float sizeY, Color textColor, int textSize)
{
    text.setFont(font);
    text.setString(textString);
    text.setPosition(sizeX, sizeY);
    position = { sizeX, sizeY };
    text.setFillColor(textColor);
    text.setCharacterSize(textSize);
}

TextObject::~TextObject()
{
}

void TextObject::Init()
{
}

void TextObject::Update(float dt)
{
    text.setPosition(position);
}

void TextObject::Draw(RenderWindow& window)
{
    window.draw(text);
}

void TextObject::Translate(Vector2f delta)
{
    position.x += delta.x;
    position.y += delta.y;
}

void TextObject::SetOrigin(Origins origin)
{
    Utils::SetOrigin(text, origin);
}

void TextObject::SetString(string string)
{
    text.setString(string);
}