#pragma once
#include <SFML/Graphics.hpp>
#include "../Framework/Utils.h"
#include "../GameObject/Object.h"

using namespace sf;

class Bat : public Object
{
private:
	RectangleShape shape;
	float speed;
	Vector2f curDir;

public:
	Bat();
	virtual ~Bat();

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	float GetSpeed() const;
	void SetSpeed(float speed);

	void SetOrigin(Origins origin);

	FloatRect GetBounds() const;
};