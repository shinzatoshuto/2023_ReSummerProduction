#include "Image.h"

int Image::TitleImg;
int Image::MarioImg[9];

int Image::DrawImages()
{
	if (LoadDivGraph("1-1image/Mario/mario.png", 9, 9, 1, 32, 32, MarioImg) == -1)return -1;

	return 0;
}