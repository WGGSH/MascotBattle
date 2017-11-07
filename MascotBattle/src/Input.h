#pragma once
#include "Singleton.h"
#include "Define.h"

class Input final : public Singleton<Input> {
	Input() = default;
	friend Singleton<Input>;
private:
	int mousePressCount; // マウスがクリックされ続けたフレーム数
	int mouseReleaseCount; // マウスが離され続けたフレーム数

	int keyPresseCount[Define::KEY_MAX]; // キーが入力され続けたフレーム数
	int keyReleaseCount[Define::KEY_MAX]; // キーが離され続けたフレーム数

public:
	void update(); // 更新

	bool getKey(int)const; // 押されているか判定
	bool getKeyDown(int)const; // 押された瞬間か判定
	bool getKeyUp(int)const; // 話された瞬間か判定

};