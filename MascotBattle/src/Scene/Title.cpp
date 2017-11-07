#include "Title.h"
#include "../Input.h"
#include "../Scene.h"
#include "InGame.h"

#include "./DxLib.h"

Title::Title() {
}

Title::~Title() {
}

bool Title::update() {
	if (Input::Instance()->getButton(PLAYER::PLAYER_1, INPUTBUTTON::SHOT)) {
		Scene::Instance()->push(new InGame());
		return false;
	}
	return true;
}

void Title::draw()const {
	DrawCircle(100, 100, 100, 0xffffff, TRUE);
}