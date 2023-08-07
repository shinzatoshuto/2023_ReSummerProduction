#pragma once
#include "DxLib.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <regex>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "BoxCollider.h"

#define Map_Size 32

class StageA:public BoxCollider
{
public:
	std::vector<std::vector<int>> MapData;
	RECT srct[16][220];

public:
	StageA()
	{

	};
	void LoadMapdata();
	void Update();
	void DrawStage();

};

