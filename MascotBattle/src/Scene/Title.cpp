#include "Title.h"
#include "InGame.h"
#include "../Input.h"
#include "../Scene.h"
#include "./DxLib.h"

Title::Title() {
}

Title::~Title() {
}

// ‰Šú‰»ˆ—
void Title::initialize() {
}

// ƒƒCƒ“ƒ‹[ƒv
bool Title::update() {
	if (Input::Instance()->getButton(PLAYER_1, SHOT)) {
		Scene::Instance()->push(new InGame());
	}
	if (Input::Instance()->getButton(PLAYER_1, BOM)) {
		return false;
	}
	return true;
}

// •`‰æˆ—
void Title::draw()const {
	DrawCircle(100, 100, 100, 0xffffff, TRUE);
}