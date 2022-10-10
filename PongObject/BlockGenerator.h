#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Block.h"
#include <fstream>
#include <vector>
#include <string>

using namespace sf;
using namespace std;

class BlockGenerator
{
private:
	vector<string>* ReadFile(string path);

public:
	BlockGenerator();
	~BlockGenerator();

	bool GetBlocks(list<Block*>& blocks, int width, int stageIdx);
};