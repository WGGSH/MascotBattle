#include "Title.h"
#include "InGame.h"
#include "../Input.h"
#include "../Scene.h"
#include "./DxLib.h"

Title::Title() {
}

Title::~Title() {
}

// 初期化処理
void Title::initialize() {
}

// メインループ
bool Title::update() {
	if (Input::Instance()->getButton(PLAYER_1, SHOT)) {
		Scene::Instance()->push(new InGame());
	}
	if (Input::Instance()->getButton(PLAYER_1, BOM)) {
		return false;
	}
	return true;
}

// 描画処理
void Title::draw()const {
	DrawCircle(100, 100, 100, 0xffffff, TRUE);
}