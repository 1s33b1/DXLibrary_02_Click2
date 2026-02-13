#include "DxLib.h"
#include "Target.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int MouseX, MouseY;

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;
	SetGraphMode(640, 320, 30);
	SetDrawScreen(DX_SCREEN_BACK);
	
	Target myTarget; // Targetクラスのインスタンス
	Target* pTarget = &myTarget; // Targetの住所をポインタに保持
	unsigned int color = GetColor(0, 255, 0);
	unsigned int boxcolor = GetColor(0, 0, 255);

	SetMouseDispFlag(TRUE);
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		GetMousePoint(&MouseX, &MouseY);

		//myTarget.Update();
		//myTarget.Draw();
		
		//pTarget->x += 100;
		pTarget->Update();
		pTarget->Draw();

		DrawBox(0, 0, 640, 32, boxcolor, TRUE);

		DrawFormatString(0, 0, color, "座標X %d	座標Y %d", MouseX, MouseY);
		WaitTimer(50);
		ScreenFlip();
	}
	delete pTarget; // ゲームを終了するときにポインタを削除
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}