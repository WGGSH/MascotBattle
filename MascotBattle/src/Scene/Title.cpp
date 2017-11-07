#include "Title.h"

#include "./DxLib.h"

Title::Title() {
}

Title::~Title() {
}

bool Title::update() {
	return true;
}

void Title::draw()const {
	DrawCircle(100, 100, 100, 0xffffff, TRUE);
}