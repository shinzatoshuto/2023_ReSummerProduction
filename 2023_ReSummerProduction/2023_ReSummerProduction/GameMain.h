#pragma once
#include "AbsScene.h"
#include "DxLib.h"
#include "Player.h"
#include "StageA.h"

class GameMain : public AbsScene
{
private:
	int imgCn;
	int waitCn;
	int Count;
	Player* player;
	StageA* stage;

public:
	GameMain();
	virtual ~GameMain() 
	{
		delete player;
	};
	virtual AbsScene* Update() override;
	virtual void Draw() const override;
};

