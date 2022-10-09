#pragma once
#include <SFML/Graphics.hpp>
#include "../Framework/Utils.h"
#include "../GameObject/Object.h"
#include "Block.h"

using namespace sf;
using namespace std;

class Ball : public Object
{
private:
	CircleShape shape;
	float speed;
	Vector2f curDir;
	const Vector2f initPos;

public:
	Ball(Vector2f _initPos);
	virtual ~Ball();

	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	void Fire(Vector2f dir, float speed);

	void SetSpeed(float speed);
	float GetSpeed() const;

	void SetOrigin(Origins origin);

	FloatRect GetBounds() const;

	void OnCollisionTop();
	void OnCollisionSides(float width);
	void OnCollisionBottom();
	void OnCollisionBat();
	void OnCollisionBlock(Block* block);
};