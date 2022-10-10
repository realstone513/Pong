#include "BlockGenerator.h"
#include <sstream>

BlockGenerator::BlockGenerator()
{
}

BlockGenerator::~BlockGenerator()
{
}

bool BlockGenerator::GetBlocks(list<Block*>& blocks, int width, int stageIdx)
{
	vector<string>* temp = nullptr;
	string path = "Stage/Stage";
	if (stageIdx < 10)
		path += ((stageIdx < 10) ? "0" + to_string(stageIdx) : to_string(stageIdx)) + ".psf";

	if (!(temp = ReadFile(path)))
		return false;

	stringstream ss;
	vector<int> settings;
	int num;
	ss.str(temp[0][0]);
	while (ss >> num)
		settings.push_back(num);
	if (settings.size() != 3)
		return false;

	int rowCount = settings[0];
	int colCount = settings[1];
	int offset = settings[2];

	float sizeX = width / rowCount;
	Vector2f blockSize(sizeX - offset * 2, sizeX * 0.75f);

	int nextY = 100; // UI 겹치지않게함
	for (int y = 0; y < colCount; y++)
	{
		int nextX = offset;
		string tempString = (*temp)[y + 1];
		for (int x = 0; x < rowCount; x++)
		{
			int type = tempString[x] - '0';
			if (type != 0)
				blocks.push_back(new Block(nextX, nextY, blockSize, type));
			nextX += blockSize.x + offset * 2;
		}
		nextY += blockSize.y + offset * 2;
	}
	return true;
}

vector<string>* BlockGenerator::ReadFile(string path)
{
	ifstream ifs;
	ifs.open(path);
	if (!ifs)
		return nullptr;

	string buf;
	vector<string>* bundle = new vector<string>;
	while (getline(ifs, buf))
	{
		bundle->push_back(buf);
	}
	ifs.close();
	return bundle; 
}