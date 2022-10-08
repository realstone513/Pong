#include "BlockGenerator.h"

BlockGenerator::BlockGenerator()
{
}

BlockGenerator::~BlockGenerator()
{
}

list<Block*> BlockGenerator::GetBlocks(int width,
	int rowCount, int colCount, int offset)
{
	list<Block*> blocks;
	float sizeX = width / rowCount;
	Vector2f blockSize(sizeX - offset * 2, sizeX * 0.75f);

	int nextY = 100; // UI 겹치지않게함
	for (int y = 0; y < colCount; y++)
	{
		int nextX = offset;
		for (int x = 0; x < rowCount; x++)
		{
			blocks.push_back(new Block(nextX, nextY, blockSize));
			nextX += blockSize.x + offset * 2;
		}
		nextY += blockSize.y + offset * 2;
	}
	return blocks;
}