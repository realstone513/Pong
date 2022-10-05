#include "Utils.h"

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
	return vec.x * vec.x + vec.y * vec.y;
}

Vector2f Utils::Normalize(const Vector2f& vec)
{
	return Vector2f();
}