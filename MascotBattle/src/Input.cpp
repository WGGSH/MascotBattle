// --- Input.cpp ---
#include "Input.h"
#include "DxLib.h"

// 入力情報の更新
void Input::update() {

	// マウスの入力状態を取得
	if (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) {
		if (this->mouseReleaseCount>0)this->mouseReleaseCount = 0;
		this->mousePressCount++;
	}
	else {
		if (this->mousePressCount>0)this->mousePressCount = 0;
		this->mouseReleaseCount++;
	}

	// 全てのキーの入力状態を取得
	char keys[Define::KEY_MAX];
	DxLib::GetHitKeyStateAll(keys);
	// 全てのキーについて調べる
	for (int i = 0; i < Define::KEY_MAX; i++) {
		if (keys[i] == 1) {
			// そのキーが押されている
			if (this->keyReleaseCount[i] > 0)this->keyReleaseCount[i] = 0;
			this->keyPresseCount[i]++;
		}
		else {
			// そのキーが押されていない
			if (this->keyPresseCount[i] > 0)this->keyPresseCount[i] = 0;
			this->keyReleaseCount[i]++;
		}
	}

#ifdef _DEBUG
	// デバック時:入力情報を表示
	DxLib::printfDx("%d:%d\n", this->mousePressCount, this->mouseReleaseCount);
#endif
}

// 指定のキーが押されているかを取得
bool Input::getKey(int key) const {
	return this->keyPresseCount[key] > 0;
}

// 指定のキーが押された瞬間かを取得
bool Input::getKeyDown(int key)const {
	return this->keyPresseCount[key] == 1;
}

// 押されていた指定のキーが離された瞬間かを取得
bool Input::getKeyUp(int key) const {
	return this->keyReleaseCount[key] == 1;
}