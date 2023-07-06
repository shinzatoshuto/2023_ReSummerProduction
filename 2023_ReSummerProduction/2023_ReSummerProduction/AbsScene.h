#pragma once
class AbsScene
{
public:
	//デストラクタ
	virtual ~AbsScene() {};

	//描画以外の更新を実行
	virtual AbsScene* Update() = 0;

	//描画に関することの実装
	virtual void Draw() const = 0;
};

