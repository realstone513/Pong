#pragma once
#include <SFML/Graphics.hpp>
#include "../3rd/SingleTon.h"

#define FRAMEWORK (Framework::GetInstance())

using namespace sf;

class Framework : public Singleton<Framework>
{
protected:
	RenderWindow window;
	Vector2i windowSize;
	Clock clock;
	Time deltaTime;
	float timeScale;

public:
	Framework();
	virtual ~Framework();

	float GetDT() const;
	float GetRealDT() const;
	const Vector2i& GetWindowSize() const;

	bool Init(int width, int height);
	bool Do();
};