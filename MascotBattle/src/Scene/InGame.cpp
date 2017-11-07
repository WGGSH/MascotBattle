#include "InGame.h"
#include "./DxLib.h"

InGame::InGame() {
}

InGame::~InGame() {
}

// ‰Šú‰»ˆ—
void InGame::initialize() {
}

// ƒƒCƒ“ƒ‹[ƒv
bool InGame::update() {
	return true;
}

// •`‰æˆ—
void InGame::draw()const {
	DrawCircle(100, 100, 100, 0xff0000, TRUE);
}