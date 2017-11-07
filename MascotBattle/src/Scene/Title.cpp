#include "Title.h"
#include "InGame.h"
#include "../Input.h"
#include "../Scene.h"
#include "./DxLib.h"

Title::Title() {
}

Title::~Title() {
}

// ����������
void Title::initialize() {
}

// ���C�����[�v
bool Title::update() {
	if (Input::Instance()->getButton(PLAYER_1, SHOT)) {
		Scene::Instance()->push(new InGame());
	}
	if (Input::Instance()->getButton(PLAYER_1, BOM)) {
		return false;
	}
	return true;
}

// �`�揈��
void Title::draw()const {
	DrawCircle(100, 100, 100, 0xffffff, TRUE);
}