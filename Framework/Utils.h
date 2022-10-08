#pragma once
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
using namespace std;

enum class Origins
{
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
};

class Utils
{
private:
	static random_device rd;
	static mt19937 gen;
public:
	static void SetOrigin(Transformable& obj, Origins origin, FloatRect rect);
	static void SetOrigin(Text& obj, Origins origin);
	static void SetOrigin(Sprite& obj, Origins origin);
	static void SetOrigin(Shape& obj, Origins origin);
	
	static int Random(int min, int maxExclude);
	static float Random(float min, int maxInclude);

	static float DotProduct2d(
		const Vector2f& vec1, const Vector2f& vec2);
	static float Magnitude(const Vector2f& vec);
	static float SqrMagnitude(const Vector2f& vec);
	static Vector2f Normalize(const Vector2f& vec);
	static float GetAngleBetweenTwoVec(
		const Vector2f& vec1, const Vector2f& vec2);
};