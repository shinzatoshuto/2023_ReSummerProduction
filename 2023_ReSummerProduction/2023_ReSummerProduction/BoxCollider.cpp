#include "BoxCollider.h"
#include <math.h>

RECT BoxCollider::rct;
float BoxCollider::width;
float BoxCollider::height;

bool BoxCollider::HitBox(RECT Player, RECT Object)
{
	//Box��Box�̓����蔻��
	//�������瑊��̃x�N�g�������߂�
	RECT rct = Object;

	bool rec = false;

	//��̓����蔻��
	if (Player.top - 2 < rct.bottom)
	{
		if (Player.left >= rct.left
			&& Player.left <= rct.right
			&& Player.bottom > rct.top)
			rec = true;

		if (Player.right >= rct.left
			&& Player.right <= rct.right
			&& Player.bottom > rct.top)
			rec = true;
	}

	//���̓����蔻��
	if (Player.bottom + 2 > rct.top)
	{
		if (Player.left >= rct.left
			&& Player.left <= rct.right
			&& Player.top < rct.bottom)
			rec = true;

		if (Player.right >= rct.left
			&& Player.right <= rct.right
			&& Player.top < rct.bottom)
			rec = true;
	}

	//���̓����蔻��
	if (Player.left - 2 < rct.right)
	{
		if (Player.top >= rct.top
			&& Player.top <= rct.bottom
			&& Player.right > rct.left)
			rec = true;

		if (Player.bottom >= rct.top
			&& Player.bottom <= rct.bottom
			&& Player.right > rct.left)
			rec = true;
	}

	//�E�̓����蔻��
	if (Player.right + 2 > rct.left)
	{
		if (Player.top >= rct.top
			&& Player.top <= rct.bottom
			&& Player.left < rct.right)
			rec = true;

		if (Player.bottom >= rct.top
			&& Player.bottom <= rct.bottom
			&& Player.left < rct.right)
			rec = true;
	}

	return rec;
}