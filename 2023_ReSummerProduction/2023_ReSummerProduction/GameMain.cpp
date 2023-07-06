#include "GameMain.h"
#include "FPS.h"

GameMain::GameMain()
{
	player = new Player();
	stage = new StageA();
}

AbsScene* GameMain::Update()
{
	player->getStage(stage->maxY);
	player->Update();
	return this;
}

void GameMain::Draw() const
{
	stage->DrawStage();
	player->PDraw();
	FPS::Draw();
}