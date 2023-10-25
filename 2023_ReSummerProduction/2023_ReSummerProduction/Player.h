#pragma once
#include "DxLib.h"
#include "PadInput.h"
#include "Image.h"
#include "BoxCollider.h"

#define MaxSpeed 4.f
#define MinSpeed 2.5f

#define Gravity 1

#define walkTime 60*0.8
#define runTime 60*0.2

#define Inertia 0.1f

#define Player_Width 20
#define Player_Height 32

class Player: public BoxCollider
{
private:

	int stageY;
	int JampY;
	int Stoping;
	int OldKey;
	bool isPresse;
	float StrongPower;
	float JampStop;
	float oldJamp;
	int Change;
	int Switch;
	int WalkWait;

public:
	float SpeedL;
	float SpeedR;
	RECT prct;
	float x, y;
	float JampPower;
	float GravityPower;
	float Sub;
	bool isJamp;
	bool isGround;
	bool isHit;
	bool isScroll;
	float Scrollnum;

public:
	Player();
	void Update();
	void PDraw();  //Player(マリオ)の描画
	void PMove();  //Player(マリオ)の動き
	void Jamp();
};

