#include "Title.h"
#include "../Input.h"
#include "../Scene.h"
#include "InGame.h"

#include "./DxLib.h"

Title::Title() {
}

Title::~Title() {
}

void Title::initialize() {
}

bool Title::update() {
	if (Input::Instance()->getButton(PLAYER_1, SHOT)) {
		Scene::Instance()->push(new InGame());
	}
	if (Input::Instance()->getButton(PLAYER_1, BOM)) {
		return false;
	}
	return true;
}

void Title::draw()const {
	DrawCircle(100, 100, 100, 0xffffff, TRUE);
}