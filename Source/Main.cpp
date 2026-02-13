#include "DxLib.h"
#include "Target.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int mx, my;

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;
	SetGraphMode(640, 320, 30);
	SetDrawScreen(DX_SCREEN_BACK);
	
	Target myTarget; // Targetクラスのインスタンス
	//Target* pTarget = &myTarget; // Targetの住所をポインタに保持
	SetMouseDispFlag(TRUE);
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに

		GetMousePoint(&mx, &my);

		// --- ここでターゲットの処理 ---
		myTarget.Update(mx,my); // 移動処理（Target.cppに書いていく）
		myTarget.Draw();   // 描画処理（Target.cppに書いていく）

		ScreenFlip();    // 画面を更新して、少し休む	
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}