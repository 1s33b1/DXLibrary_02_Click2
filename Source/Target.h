#pragma once
class Target {
public:
	int x, y;
	int radius;
	bool isVisible;

	// コンストラクタ
	Target();
	// 更新メソッド
	void Update();
	// 描画メソッド
	void Draw();
};