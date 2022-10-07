#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Block.h"

using namespace sf;
using namespace std;

class BlockGenerator
{
private:
	list<Block*> blocks;

public:
	BlockGenerator(int width,
		int rowCount = 15, int colCount = 10, int offset = 1);
	~BlockGenerator();

	list<Block*> GetBlocks() const;
};