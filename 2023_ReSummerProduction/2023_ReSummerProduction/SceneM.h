#pragma once
#include "AbsScene.h"

class SceneM : public AbsScene
{
private:
	AbsScene* mScene;   //���݂̃V�[��

public:
	//�R���X�g���N�^
	SceneM(AbsScene* Scene) :mScene(Scene) {};

	//�f�X�g���N�^
	~SceneM() {
		delete mScene;
	}

	//�`��ȊO�̍X�V������
	virtual AbsScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;

};

