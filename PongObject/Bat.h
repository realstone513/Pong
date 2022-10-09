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
	const Vector2f initPos;

public:
	Bat(Vector2f _initPos);
	virtual ~Bat();

	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	float GetSpeed() const;
	void SetSpeed(float speed);

	void SetOrigin(Origins origin);

	FloatRect GetBounds() const;
};