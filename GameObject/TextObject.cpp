#include "TextObject.h"

TextObject::TextObject(Font& font, string textString,
    float sizeX, float sizeY, Color textColor, int textSize)
{
    text.setFont(font);
    text.setString(textString);
    text.setPosition(sizeX, sizeY);
    text.setFillColor(textColor);
    text.setCharacterSize(textSize);
}

TextObject::~TextObject()
{
}

void TextObject::Init()
{
}

void TextObject::Update()
{
}

void TextObject::Draw(RenderWindow& window)
{
    window.draw(text);
}