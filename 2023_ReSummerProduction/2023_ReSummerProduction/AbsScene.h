#pragma once
class AbsScene
{
public:
	//�f�X�g���N�^
	virtual ~AbsScene() {};

	//�`��ȊO�̍X�V�����s
	virtual AbsScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ̎���
	virtual void Draw() const = 0;
};

