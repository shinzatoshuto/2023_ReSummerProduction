#pragma once
#include "DxLib.h"
#include "PadInput.h"
#include "Image.h"

#define MaxSpeed 4.f
#define MinSpeed 2.f

#define walkTime 60*0.8
#define runTime 60*0.2

#define Inertia 0.1f

class Player
{
private:
	float x, y;
	int stageY;
	int JampY;
	int JampST;
	int Stoping;
	float SpeedL;
	float SpeedR;
	int OldKey;

	bool isJamp;
	bool isGround;

public:
	Player();
	void Update();
	void PDraw();  //Player(マリオ)の描画
	void PMove();  //Player(マリオ)の動き
	void getStage(int y);
	void Jamp();
};

