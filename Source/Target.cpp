#include "DxLib.h"
#include "Target.h"
/// <summary>
/// ターゲットの生成を行うプログラム
/// </summary>

Target::Target() {
	x = 320; y = 240;
	radius = 30;
	isVisible = true;
}

// 更新処理
void Target::Update()
{
	// 移動処理とかを書く
	x += 10;
}

// 描画処理
void Target::Draw()
{
	if (isVisible) {
		DrawCircle(x, y, radius, GetColor(255, 0, 0), TRUE);
	}
}