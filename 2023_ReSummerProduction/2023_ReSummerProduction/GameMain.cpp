#include "GameMain.h"

GameMain::GameMain()
{
    player = new Player();

    stage = new StageA();
	stage->LoadMapdata();
    imgCn = 0;
    Count = 0;
    waitCn = 0;
}

AbsScene* GameMain::Update()
{
    for (int i = 0; i < stage->MapData.size(); i++)
    {
        for (int j = 0; j < stage->MapData[i].size(); j++)
        {
            RECT rc = { player->Scrollnum,player->prct.top,player->Scrollnum + Player_Width,player->prct.bottom };
            if (player->HitBox(rc, stage->srct[i][j]))
            {
                if (stage->MapData[i][j] == 1)
                {
                    player->isHit = true;
                    player->y = stage->srct[i][j].top - 32;
                }
            }
        }
    }


    player->Update();

    if (Count++ >= 10)
    {
        Count = 0;
        if (waitCn++ > 1)
        {
            if (imgCn++ > 2)
            {
                waitCn = 0;
                imgCn = 0;
            }
        }
    }

    stage->GetAnimCount(imgCn);

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
}