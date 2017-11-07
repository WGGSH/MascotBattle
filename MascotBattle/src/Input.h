#pragma once
#include "Singleton.h"
#include "Define.h"

// ゲーム内ボタン
enum INPUTBUTTON {
	DOWN,LEFT,RIGHT,UP,
	SHOT,BOM,
};

// プレイヤー番号
enum PLAYER {
	PLAYER_1,PLAYER_2,
};

// 入力ボタン情報
struct InputButtonState {
	int pressCount; // 押し続けられた時間
	int releaseCount; // 離され続けた時間
	int keyCode; // 対応するキーボード
	int padInput; // 対応するゲームパッドのボタン
};

// Inputクラス
class Input final : public Singleton<Input> {
	Input() = default;
	friend Singleton<Input>;
private:
	int padNum; // パッドの入力数
	int keyPresseCount[Define::KEY_MAX]; // キーが入力され続けたフレーム数
	int keyReleaseCount[Define::KEY_MAX]; // キーが離され続けたフレーム数

	InputButtonState inputButtonState[Define::PLAYER_MAX][Define::INPUT_BUTTON_MAX]; // ゲーム内ボタンの入力状態

	int inputButtonPressCount[Define::INPUT_BUTTON_MAX]; // ゲーム内ボタンの入力され続けたフレーム数
	int inputButtonReleaseCount[Define::INPUT_BUTTON_MAX]; // ゲーム内ボタンの離され続けたフレーム数

public:
	void setup(); // 初期化処理
	void update(); // 更新

	bool getKey(int)const; // 押されているか判定
	bool getKeyDown(int)const; // 押された瞬間か判定
	bool getKeyUp(int)const; // 話された瞬間か判定

	bool getButtonDown(PLAYER, INPUTBUTTON) const; // ボタンが押された瞬間か判定
	bool getButtonUp(PLAYER, INPUTBUTTON)const; // ボタンが離された瞬間か判定
	bool getButton(PLAYER, INPUTBUTTON)const; // ボタンが押されているか判定
};