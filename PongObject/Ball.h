#pragma once
#include "../GameObject/Object.h"
#include "Bat.h"
#include "Block.h"

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
	void OnCollisionBat(Bat* bat);
	void OnCollisionBlock(Block* block);
};