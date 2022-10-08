#pragma once
#include "Object.h"

class TextObject : public Object
{
protected:
    Text text;

public:
    TextObject(Font& font,
        string textString,
        float sizeX = 0, float sizeY = 0,
        Color textColor = Color::White,
        int textSize = 75);
    virtual ~TextObject();

    virtual void Init();
    virtual void Update();
    virtual void Draw(RenderWindow& window);
};