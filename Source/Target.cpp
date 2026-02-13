#include "DxLib.h"
#include "Target.h"

/// <summary>
/// ターゲットの移動を行わせる
/// </summary>

Target::Target() {
	targetX = 320; targetY = 240; // ターゲットのXY座標
	radius = 30; // ターゲットの半径
	isVisible = true; // true:表示状態
	isFlip = false; // ウィンドウ
	targetSpeed = 5;
}

// 更新処理
void Target::Update(int mouseX,int mouseY)
{
	// 移動処理とかを書く
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { // 左クリックが押されたとき
		int dx = mouseX - targetX;
		int dy = mouseY - targetY;

		if ((dx * dx) + (dy + dy) <= (radius * radius)) {
			isVisible = false; // 非表示にする
		}
	}

	// 反転しているときもしくはしていないときの処理
	{
		if (isFlip) {
			targetX += targetSpeed;
		}
		else {
			targetX -= targetSpeed;
		}
	}

	// フラグを立てるときと立てないとき
	{
		if (targetX < 0) {
			targetX = 0 + radius;
			//isFlip = false;
			isFlip = true;
		}
		if (targetX > 640 - radius) {
			targetX = 640 - radius;
			//isFlip = true;
			isFlip = false;
		}
	}

	if (!isVisible) { // 非表示状態
		WaitTimer(3000); // 5秒間待機
		targetX = GetRand(640 - radius);
		targetY = GetRand(480 - radius);
		isVisible = true;
	}
}

// 描画処理
void Target::Draw()
{
	if (isVisible) {
		DrawCircle(targetX, targetY, radius, GetColor(255, 0, 0), TRUE);
	}
}