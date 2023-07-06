#pragma once
#include "AbsScene.h"

class SceneM : public AbsScene
{
private:
	AbsScene* mScene;   //現在のシーン

public:
	//コンストラクタ
	SceneM(AbsScene* Scene) :mScene(Scene) {};

	//デストラクタ
	~SceneM() {
		delete mScene;
	}

	//描画以外の更新を実装
	virtual AbsScene* Update() override;

	//描画に関することを実装
	virtual void Draw() const override;

};

