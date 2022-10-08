#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Block.h"

using namespace sf;
using namespace std;

class BlockGenerator
{
public:
	BlockGenerator();
	~BlockGenerator();

	static list<Block*> GetBlocks(int width,
		int rowCount = 15, int colCount = 10, int offset = 1);
};