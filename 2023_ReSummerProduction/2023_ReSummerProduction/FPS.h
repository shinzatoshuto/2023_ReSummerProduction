#pragma once
#include "DxLib.h"

class FPS
{
private:
	static const int fps = 60;
	static int mStartTime;      //測定開始時刻
	static int mCount;          //カウンタ
	static float mFps;          //fps

public:
	static void Initfps();
	static void Update();
	static void Draw();
	static void Wait();

};

