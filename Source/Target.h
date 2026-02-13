#pragma once
class Target {
public:
	int targetX, targetY;
	int radius;
	int targetSpeed; // ターゲットの移動速度
	bool isVisible;
	bool isFlip;

	// コンストラクタ
	Target();
	// 更新メソッド
	void Update(int mouseX, int mouseY); // マウスの座標をもらって当たり判定を行う
	// 描画メソッド
	void Draw();
};