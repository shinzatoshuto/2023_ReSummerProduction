#define _CRT_SECURE_NO_WARNINGS
#include "StageA.h"
#include <stdio.h>

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

void StageA::MapScroll(float pSpeed)
{
	x += pSpeed;
}

void StageA::DrawStage()
{
	for (int i = 0; i < MapData.size(); i++)
	{
		for (int j = 0; j < MapData[i].size(); j++)
		{
			for (int h = 0; h < sizeof(graph) / sizeof(int); h++)
			{
				if (graph[h][0] == MapData[i][j])
				{
					DrawGraph(j * Map_Size - x, i * Map_Size, graph[h][1], TRUE);
				}
			}

			if (MapData[i][j] == 1 || MapData[i][j] == 6)
			{
				DrawBox(srct[i][j].left - x, srct[i][j].top, srct[i][j].right - x, srct[i][j].bottom, 0xffffff, FALSE);
			}
		}
	}
}