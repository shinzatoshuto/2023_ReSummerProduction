#include "SceneM.h"

AbsScene* SceneM::Update()
{
	//���݂̃V�[���̃A�b�v�f�[�g�����s
	AbsScene* next = mScene->Update();

	//���̃V�[�������݂̃V�[���ƈႤ�ꍇ�؂�ւ���
	if (next != mScene)
	{
		delete mScene;
		mScene = next;
	}

	return next;
}

void SceneM::Draw() const
{
	mScene->Draw();
}