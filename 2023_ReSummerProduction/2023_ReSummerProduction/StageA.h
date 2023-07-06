#pragma once
#include "DxLib.h"

class StageA
{
public:
	int maxX, maxY, minX;

public:
	StageA()
	{
		minX = 0;
		maxX = 640;
		maxY = 400;
	}
	void DrawStage();
};

