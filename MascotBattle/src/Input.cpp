// --- Input.cpp ---
#include "Input.h"
#include "DxLib.h"

void Input::setup() {
	this->padNum = DxLib::GetJoypadNum();

	// 1Pモード
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::DOWN].keyCode = KEY_INPUT_S;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::LEFT].keyCode = KEY_INPUT_A;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::RIGHT].keyCode = KEY_INPUT_D;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::UP].keyCode = KEY_INPUT_W;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::SHOT].keyCode = KEY_INPUT_Z;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::BOM].keyCode = KEY_INPUT_X;

	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::DOWN].padInput = PAD_INPUT_DOWN;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::LEFT].padInput = PAD_INPUT_LEFT;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::RIGHT].padInput = PAD_INPUT_RIGHT;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::UP].padInput = PAD_INPUT_UP;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::SHOT].padInput = PAD_INPUT_1;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::BOM].padInput = PAD_INPUT_2;


	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::DOWN].keyCode = KEY_INPUT_K;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::LEFT].keyCode = KEY_INPUT_J;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::RIGHT].keyCode = KEY_INPUT_L;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::UP].keyCode = KEY_INPUT_I;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::SHOT].keyCode = KEY_INPUT_B;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::BOM].keyCode = KEY_INPUT_N;

	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::DOWN].padInput = PAD_INPUT_DOWN;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::LEFT].padInput = PAD_INPUT_LEFT;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::RIGHT].padInput = PAD_INPUT_RIGHT;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::UP].padInput = PAD_INPUT_UP;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::SHOT].padInput = PAD_INPUT_1;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::BOM].padInput = PAD_INPUT_2;
}

// 入力情報の更新
void Input::update() {
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

	// ゲームパッドの入力状態を取得
	//if (this->padNum >= 1) {
	for(int i=0;i<Define::PLAYER_MAX;i++){
		int pad = DxLib::GetJoypadInputState(i+1);
		for (int j = 0; j < Define::INPUT_BUTTON_MAX; j++) {
			// キーボードとゲームパッド片方でも入力されていると，入力状態と判定
			if (this->keyPresseCount[this->inputButtonState[i][j].keyCode] >= 1 || (pad & this->inputButtonState[i][j].padInput)) {
				if (this->inputButtonState[i][j].releaseCount > 0)this->inputButtonState[i][j].releaseCount = 0;
				this->inputButtonState[i][j].pressCount++;
			}
			else {
				if (this->inputButtonState[i][j].pressCount > 0)this->inputButtonState[i][j].pressCount = 0;
				this->inputButtonState[i][j].releaseCount++;
			}
		}
	}

#ifdef _DEBUG
	// デバック時:入力情報を表示
	for (int i = 0; i < Define::KEY_MAX; i++) {
		if (this->keyPresseCount[i] >= 1) {
			printfDx("%d:%d ", i, this->keyPresseCount[i]);
		}
	}
	printfDx("\n");

	for (int i = 0; i < Define::PLAYER_MAX; i++) {
		for (int j = 0; j < Define::INPUT_BUTTON_MAX; j++) {
			if (this->inputButtonState[i][j].pressCount >= 1) {
				printfDx("P%d-%d:%d ", i + 1, j, this->inputButtonState[i][j].pressCount);
			}
		}
	}
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

// ボタンが押された瞬間か判定
bool Input::getButtonDown(PLAYER player, INPUTBUTTON button)const {
	return this->inputButtonState[player][button].pressCount == 1;
}

// ボタンが離された瞬間か判定
bool Input::getButtonUp(PLAYER player, INPUTBUTTON button)const {
	return this->inputButtonState[player][button].releaseCount == 1;
}

// ボタンが押されているか判定
bool Input::getButton(PLAYER player, INPUTBUTTON button)const {
	return this->inputButtonState[player][button].pressCount >= 1;
}