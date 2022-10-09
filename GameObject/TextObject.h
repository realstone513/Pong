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
    virtual ~TextObject() override;

    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Draw(RenderWindow& window) override;

    virtual void Translate(Vector2f delta) override;

    void SetOrigin(Origins origin);
    void SetString(string string);
};