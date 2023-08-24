#include "GameMain.h"
#include "FPS.h"

GameMain::GameMain()
{
    player = new Player();

    stage = new StageA();
	stage->LoadMapdata();
}

AbsScene* GameMain::Update()
{
    for (int i = 0; i < stage->MapData.size(); i++)
    {
        for (int j = 0; j < stage->MapData[i].size(); j++)
        {
            if (stage->MapData[i][j] == 1)
            {
                if (player->HitBox(player->prct, stage->srct[i][j]))
                {
                    player->isHit = true;
                    player->y = stage->srct[i][j].top - 32;
                }
            }
            if (stage->MapData[i][j] == 6)
            {
                if (player->HitBox(player->prct, stage->srct[i][j]))
                {

                }
            }
        }
    }

    player->Update();

    if (player->isScroll && player->SpeedR > 0)
    {
        stage->MapScroll(player->SpeedR);
    }
    else player->isScroll = false;

	return this;
}

void GameMain::Draw() const
{
	stage->DrawStage();
	player->PDraw();
	FPS::Draw();
}