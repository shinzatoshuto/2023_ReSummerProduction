#include "FPS.h"

const int FPS::fps;
int FPS::mCount;
float FPS::mFps;
int FPS::mStartTime;


void FPS::Initfps()
{
	mStartTime = GetNowCount();
	mCount = 0;
	mFps = 0;
}

void FPS::Update()
{
	if (mCount == 0)
	{
		mStartTime = GetNowCount();
	}
	if (mCount == fps)
	{
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)fps);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
}

void FPS::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "fps : %.1f", mFps);
}

void FPS::Wait()
{
	int tookTime = GetNowCount() - mStartTime;
	int waitTime = mCount * 1000 / fps - tookTime;

	if (waitTime > 0)
	{
		Sleep(waitTime);
	}
}