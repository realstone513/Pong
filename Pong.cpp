#include <SFML/Graphics.hpp>
#include "Frameworks.h"
#include <list>

#include "PongObject/Ball.h"
#include "PongObject/Bat.h"
#include "PongObject/Block.h"
#include "PongObject/BlockGenerator.h"

#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	int width = 1000;
	int height = 800;
	FRAMEWORK->Init(width, height);
	FRAMEWORK->Do();
	return 0;
}