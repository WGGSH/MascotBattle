#include "InGame.h"
#include "./DxLib.h"

InGame::InGame() {
}

InGame::~InGame() {
}

// ����������
void InGame::initialize() {
}

// ���C�����[�v
bool InGame::update() {
	return true;
}

// �`�揈��
void InGame::draw()const {
	DrawCircle(100, 100, 100, 0xff0000, TRUE);
}