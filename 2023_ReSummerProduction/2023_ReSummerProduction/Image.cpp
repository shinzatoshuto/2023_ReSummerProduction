#include "Image.h"

int Image::TitleImg;
int Image::MarioImg[9];
int Image::Sora;
int Image::Floor;
int Image::Mountain[6];
int Image::Grass[3];
int Image::Kumo[6];
int Image::Hatena[4];
int Image::Dokan[4];
int Image::Renga;
int Image::Kaidan;
int Image::Kara;

int Image::DrawImages()
{
	if (LoadDivGraph("1-1image/Mario/mario.png", 9, 9, 1, 32, 32, MarioImg) == -1)return -1;
	if ((Sora = LoadGraph("1-1image/sora.png")) == -1)return -1;
	if ((Floor = LoadGraph("1-1image/Block/floor.png")) == -1)return -1;
	if (LoadDivGraph("1-1image/mountain.png", 6, 6, 1, 32, 32, Mountain) == -1)return -1;
	if (LoadDivGraph("1-1image/grass.png", 3, 3, 1, 32, 32, Grass) == -1)return -1;
	if (LoadDivGraph("1-1image/kumo.png", 6, 6, 1, 32, 32, Kumo) == -1)return -1;
	if (LoadDivGraph("1-1image/Block/hatena.png", 4, 4, 1, 32, 32, Hatena) == -1)return -1;
	if ((Dokan[0] = LoadGraph("1-1image/dokan_left_up.png")) == -1)return -1;
	if ((Dokan[1] = LoadGraph("1-1image/dokan_right_up.png")) == -1)return -1;
	if ((Dokan[2] = LoadGraph("1-1image/dokan_left_down.png")) == -1)return -1;
	if ((Dokan[3] = LoadGraph("1-1image/dokan_right_down.png")) == -1)return -1;
	if ((Renga = LoadGraph("1-1image/Block/block.png")) == -1)return -1;
	if ((Kaidan = LoadGraph("1-1image/Block/kai_block.png")) == -1)return -1;
	if ((Kara = LoadGraph("1-1image/Block/kara_block.png")) == -1)return -1;

	return 0;
}