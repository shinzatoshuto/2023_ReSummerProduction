#pragma once
#include <Windows.h>

class BoxCollider
{
private:
	/********
	* RECT 構造体
	* left 四角形の左上隅のx座標を指定します。
	* top 四角形の左上隅のy座標を指定します。
	* right 四角形の右下隅のx座標を指定します。
	* bottom 四角形の右下隅のy座標を指定します。
	*********/
	static RECT rct;

	static float width, height;

public:
	BoxCollider() {};

public:
	static bool HitBox(RECT Player, RECT Object);
	
	RECT GetRect() { return rct; }    //Box の判定を取る
	float GetHeight() { return height; }  //Boxの縦の長さを取る
	float GetWidth() { return width; }  //Boxの横の長さを取る
	void SetValue(RECT &value, float width, float height)
	{
		this->width = width;
		this->height = height;
		rct.left = value.left;
		rct.top = value.top;
		rct.right = value.right + width;
		rct.bottom = value.bottom + height;
	}
};

