#pragma once
#include "DxLib.h"

class Image
{
public:
	static int TitleImg;
	static int MarioImg[];  //マリオ画像
	static int Sora;        //空画像
	static int Floor;       //地面画像
	static int Mountain[];  //山画像
	static int Grass[];     //草画像
	static int Kumo[];      //雲画像
	static int Hatena[];    //ハテナブロック画像
	static int Dokan[];     //土管画像
	static int Renga;       //レンガブロック画像
	static int Kaidan;      //階段ブロック画像
	static int Kara;        //空ブロック画像

public:
	static int DrawImages();
};

