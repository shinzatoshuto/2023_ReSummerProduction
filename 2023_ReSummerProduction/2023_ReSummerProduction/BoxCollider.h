#pragma once
#include <Windows.h>

class BoxCollider
{
private:
	/********
	* RECT �\����
	* left �l�p�`�̍������x���W���w�肵�܂��B
	* top �l�p�`�̍������y���W���w�肵�܂��B
	* right �l�p�`�̉E������x���W���w�肵�܂��B
	* bottom �l�p�`�̉E������y���W���w�肵�܂��B
	*********/
	static RECT rct;

	static float width, height;

public:
	BoxCollider() {};

public:
	static bool HitBox(RECT Player, RECT Object);
	
	RECT GetRect() { return rct; }    //Box �̔�������
	float GetHeight() { return height; }  //Box�̏c�̒��������
	float GetWidth() { return width; }  //Box�̉��̒��������
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

