#pragma once
#include "DxLib.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <regex>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "BoxCollider.h"
#include "Image.h"

#define Map_Size 32

class StageA:public BoxCollider
{
private:
	float x;
	int graph[20][2]
	{
		{0,Image::Sora},  //‹ó‰æ‘œ
		{1,Image::Floor}, //’n–Ê‰æ‘œ
		/** R‰æ‘œ **/
		{21,Image::Mountain[0]},
		{22,Image::Mountain[1]},
		{23,Image::Mountain[2]},
		{24,Image::Mountain[3]},
		{25,Image::Mountain[4]},
		{26,Image::Mountain[5]},
		/** ‰_‰æ‘œ **/
		{31,Image::Kumo[0]},
		{32,Image::Kumo[1]},
		{33,Image::Kumo[2]},
		{34,Image::Kumo[3]},
		{35,Image::Kumo[4]},
		{36,Image::Kumo[5]},
		/** ‘‰æ‘œ **/
		{41,Image::Grass[0]},
		{42,Image::Grass[1]},
		{43,Image::Grass[2]},
	};


public:
	std::vector<std::vector<int>> MapData;
	RECT srct[16][220];

public:
	StageA()
	{
		x = 0;
	};
	void LoadMapdata();
	void Update();
	void DrawStage();
	void MapScroll(float pSpeed);

};

