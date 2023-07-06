#include "DxLib.h"
#include "FPS.h"
#include "SceneM.h"
#include "PadInput.h"
#include "GameMain.h"
#include "Image.h"

#define Screen_Width 640
#define Screen_Height 480

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(Screen_Width, Screen_Height, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Image::DrawImages();

	FPS::Initfps();

	SceneM scene(dynamic_cast<AbsScene*>(new GameMain()));

	while (ProcessMessage() == 0 && scene.Update() != nullptr && !PadInput::OnClick(XINPUT_BUTTON_BACK))
	{
		ClearDrawScreen();

		FPS::Update();

		PadInput::UpdateKey();
		PadInput::StickControl();

		scene.Draw();

		FPS::Wait();
		ScreenFlip();
	}
	DxLib_End();

	return 0;   //ソフト終了
}