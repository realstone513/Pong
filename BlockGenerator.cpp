#include "BlockGenerator.h"
#include "Framework/Utils.h"

BlockGenerator::BlockGenerator(int width,
	int rowCount, int colCount, int offset)
{
	float sizeX = width / rowCount;
	Vector2f blockSize(sizeX - offset * 2, sizeX * 1.f);

	int nextY = 100; // UI 겹치지않게함
	for (int y = 0; y < colCount; y++)
	{
		int nextX = offset;
		for (int x = 0; x < rowCount; x++)
		{
			Block* block = new Block(nextX, nextY, blockSize);
			blocks.push_back(block);
			nextX += blockSize.x + offset * 2;
		}
		nextY += blockSize.y + offset * 2;
	}

}

BlockGenerator::~BlockGenerator()
{
}

list<Block*> BlockGenerator::GetBlocks() const
{
	return blocks;
}