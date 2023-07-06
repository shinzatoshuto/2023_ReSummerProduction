#include "SceneM.h"

AbsScene* SceneM::Update()
{
	//現在のシーンのアップデートを実行
	AbsScene* next = mScene->Update();

	//次のシーンが現在のシーンと違う場合切り替える
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