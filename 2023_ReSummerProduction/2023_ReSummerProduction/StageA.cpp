#define _CRT_SECURE_NO_WARNINGS
#include "StageA.h"
#include <stdio.h>
#include "Image.h"

void StageA::LoadMapdata()
{
	std::ifstream Mapcsv("MapData/stage.csv");
	int a = 0; 
	std::string str;
	std::string Map;

	//MapData.emplace_back();
	while (std::getline(Mapcsv, str))
	{
		MapData.emplace_back();
		std::stringstream ss{ str };
		while (std::getline(ss, Map, ','))
		{
			try
			{
				a = std::stoi(Map, nullptr);
				MapData[MapData.size() - 1].push_back(a);
			}
			catch (std::invalid_argument)
			{

			}
		}
	}

	for (int i = 0; i < MapData.size(); i++)
	{
		for (int j = 0; j < MapData[i].size(); j++)
		{
			if (MapData[i][j] == 1)
			{
				srct[i][j].left = j * Map_Size;
				srct[i][j].top = i * Map_Size;
				srct[i][j].right = j * Map_Size + Map_Size;
				srct[i][j].bottom = i * Map_Size + Map_Size;
			}
		}
	}
	std::cout << std::endl;
}

void StageA::Update()
{

}

void StageA::DrawStage()
{
	for (int i = 0; i < MapData.size(); i++)
	{
		for (int j = 0; j < MapData[i].size(); j++)
		{
			if (MapData[i][j] == 0)  //空の画像表示
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Sora, TRUE);
			}
			if (MapData[i][j] == 1)  //地面の画像表示
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Floor, TRUE);
			}

			/*********  山の表示  **********/
			if (MapData[i][j] == 21)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Mountain[0], TRUE);
			}
			if (MapData[i][j] == 22)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Mountain[1], TRUE);
			}
			if (MapData[i][j] == 23)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Mountain[2], TRUE);
			}
			if (MapData[i][j] == 24)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Mountain[3], TRUE);
			}
			if (MapData[i][j] == 25)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Mountain[4], TRUE);
			}
			if (MapData[i][j] == 26)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Mountain[5], TRUE);
			}

			/********* 草の画像表示 **********/
			if (MapData[i][j] == 41)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Grass[0], TRUE);
			}
			if (MapData[i][j] == 42)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Grass[1], TRUE);
			}
			if (MapData[i][j] == 43)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Grass[2], TRUE);
			}

			/******* 雲の画像表示 *******/
			if (MapData[i][j] == 31)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Kumo[0], TRUE);
			}
			if (MapData[i][j] == 32)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Kumo[1], TRUE);
			}
			if (MapData[i][j] == 33)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Kumo[2], TRUE);
			}
			if (MapData[i][j] == 34)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Kumo[3], TRUE);
			}
			if (MapData[i][j] == 35)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Kumo[4], TRUE);
			}
			if (MapData[i][j] == 36)
			{
				DrawGraph(j * Map_Size, i * Map_Size, Image::Kumo[5], TRUE);
			}

			if (MapData[i][j] == 1)
			{
				DrawBox(srct[i][j].left, srct[i][j].top, srct[i][j].right, srct[i][j].bottom, 0xffffff, FALSE);
			}
		}
	}
}