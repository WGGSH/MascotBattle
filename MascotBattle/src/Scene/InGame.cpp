#include "InGame.h"
#include "./DxLib.h"

InGame::InGame() {
}

InGame::~InGame() {
}

// 初期化処理
void InGame::initialize() {
}

// メインループ
bool InGame::update() {
	return true;
}

// 描画処理
void InGame::draw()const {
	DrawCircle(100, 100, 100, 0xff0000, TRUE);
}