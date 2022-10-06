#include "BlockGenerator.h"

BlockGenerator::BlockGenerator(int width,
	int rowCount, int colCount, int offset)
{
	float sizeX = width / rowCount;
	Vector2f blockSize(sizeX - offset, sizeX * 0.75f);

	int nextY = 100; // UI 겹치지않게함
	for (int y = 0; y < colCount; y++)
	{
		int nextX = offset;
		for (int x = 0; x < rowCount; x++)
		{
			Block* block = new Block(nextX, nextY);
			blocks.push_back(block);
			nextX += blockSize.x + offset;
		}
		nextY += blockSize.y + offset;
	}
}

BlockGenerator::~BlockGenerator()
{
}

list<Block*> BlockGenerator::GetBlocks() const
{
	return blocks;
}