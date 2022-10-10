#pragma once
#include <SFML/Graphics.hpp>
#include "../Framework/Utils.h"

using namespace sf;
using namespace std;

class Object
{
protected:
    int id;
    string name;
    bool active;

    Vector2f position;
    float rotation;
    Vector2f scale;

    static int objCount;

    Object(const Object& ref);
    Object& operator= (const Object& ref);

public:
    Object();
    virtual ~Object();

    int GetObjectID();

    virtual void SetActive(bool active);
    virtual bool GetActive() const;

    virtual void SetPosition(Vector2f pos);
    virtual Vector2f GetPosition() const;

    virtual void Init();
    virtual void Release();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);

    virtual void Translate(Vector2f delta);
};