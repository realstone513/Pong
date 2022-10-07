#include "Utils.h"

#define _USE_MATH_DEFINES
#include <math.h>

std::random_device Utils::rd;
std::mt19937 Utils::gen(Utils::rd());

void Utils::SetOrigin(Text& obj, Origins origin)
{
	FloatRect bounds = obj.getLocalBounds();
	Vector2f originPos;
	originPos.x = bounds.width * ((int)origin % 3) * 0.5f;
	originPos.y = bounds.height * ((int)origin / 3) * 0.5f;
	obj.setOrigin(originPos);
}

void Utils::SetOrigin(Sprite& obj, Origins origin)
{
	FloatRect bounds = obj.getLocalBounds();
	Vector2f originPos;
	originPos.x = bounds.width * ((int)origin % 3) * 0.5f;
	originPos.y = bounds.height * ((int)origin / 3) * 0.5f;
	obj.setOrigin(originPos);
}

void Utils::SetOrigin(Shape& obj, Origins origin)
{
	FloatRect bounds = obj.getLocalBounds();
	Vector2f originPos;
	originPos.x = bounds.width * ((int)origin % 3) * 0.5f;
	originPos.y = bounds.height * ((int)origin / 3) * 0.5f;
	obj.setOrigin(originPos);
}

int Utils::Range(int min, int maxInclude)
{
	return (gen() % (maxInclude - min + 1)) + min;
}

float Utils::Range(float min, float maxInclude)
{
	float div = maxInclude - min + 1.0f;
	std::uniform_real_distribution<> dist(min, maxInclude);
	return dist(gen);
}

float Utils::Magnitude(const Vector2f& vec)
{
	return sqrt(SqrMagnitude(vec));
}

float Utils::SqrMagnitude(const Vector2f& vec)
{
	return DotProduct2d(vec, vec);
}

Vector2f Utils::Normalize(const Vector2f& vec)
{
	float mag = Magnitude(vec);
	if (mag == 0)
		return { 0, 0 };
	return vec / mag;
}

float Utils::DotProduct2d(const Vector2f& vec1, const Vector2f& vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

float Utils::GetAngleBetweenTwoVec(const Vector2f& vec1, const Vector2f& vec2)
{
	return acos(DotProduct2d(vec1, vec2) / (Magnitude(vec1) * Magnitude(vec2))) / M_PI * 180.f;
}