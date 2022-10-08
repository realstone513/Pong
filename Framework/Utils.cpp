#include "Utils.h"

#define _USE_MATH_DEFINES
#include <math.h>

random_device Utils::rd;
mt19937 Utils::gen(Utils::rd());

void Utils::SetOrigin(Transformable& obj, Origins origin, FloatRect rect)
{
	Vector2f originPos(rect.width, rect.height);
	originPos.x *= ((int)origin % 3) * 0.5f;
	originPos.y *= ((int)origin / 3) * 0.5f;
	obj.setOrigin(originPos);
}

void Utils::SetOrigin(Text& obj, Origins origin)
{
	SetOrigin(obj, origin, obj.getLocalBounds());
}

void Utils::SetOrigin(Sprite& obj, Origins origin)
{
	SetOrigin(obj, origin, obj.getLocalBounds());
}

void Utils::SetOrigin(Shape& obj, Origins origin)
{
	SetOrigin(obj, origin, obj.getLocalBounds());
}

int Utils::Random(int min, int maxExclude)
{
	return (gen() % (maxExclude - min)) + min;
}

float Utils::Random(float min, int maxInclude)
{
	float div = maxInclude - min + 1.0f;
	std::uniform_real_distribution<> dist(min, maxInclude);
	return dist(gen);
}

float Utils::DotProduct2d(const Vector2f& vec1, const Vector2f& vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
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
		return vec;
	return vec / mag;
}

float Utils::GetAngleBetweenTwoVec(const Vector2f& vec1, const Vector2f& vec2)
{
	return acos(DotProduct2d(vec1, vec2) / (Magnitude(vec1) * Magnitude(vec2))) / M_PI * 180.f;
}