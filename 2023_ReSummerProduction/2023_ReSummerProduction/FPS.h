#pragma once
#include "DxLib.h"

class FPS
{
private:
	static const int fps = 60;
	static int mStartTime;      //����J�n����
	static int mCount;          //�J�E���^
	static float mFps;          //fps

public:
	static void Initfps();
	static void Update();
	static void Draw();
	static void Wait();

};

