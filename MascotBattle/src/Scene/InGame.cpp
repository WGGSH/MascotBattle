#include "InGame.h"

#include "./DxLib.h"

InGame::InGame() {
}

InGame::~InGame() {
}

bool InGame::update() {
	return true;
}

void InGame::draw()const {
	DrawCircle(100, 100, 100, 0xff0000, TRUE);
}