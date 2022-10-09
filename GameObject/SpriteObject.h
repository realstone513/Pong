#pragma once
#include "Object.h"

class SpriteObject : public Object
{
protected:
    Sprite sprite;

public:
    SpriteObject();
    virtual ~SpriteObject() override;

    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Draw(RenderWindow& window) override;

    void SetTexture(Texture& tex);
    void SetOrigin(Origins origin);
};