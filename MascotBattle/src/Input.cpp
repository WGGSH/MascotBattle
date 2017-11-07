// --- Input.cpp ---
#include "Input.h"
#include "DxLib.h"

void Input::setup() {
	this->padNum = DxLib::GetJoypadNum();

	// 1P���[�h
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::DOWN].keyCode = KEY_INPUT_S;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::LEFT].keyCode = KEY_INPUT_A;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::RIGHT].keyCode = KEY_INPUT_D;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::UP].keyCode = KEY_INPUT_W;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::SHOT].keyCode = KEY_INPUT_Z;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::BOM].keyCode = KEY_INPUT_X;

	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::DOWN].padInput = PAD_INPUT_DOWN;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::LEFT].padInput = PAD_INPUT_LEFT;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::RIGHT].padInput = PAD_INPUT_RIGHT;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::UP].padInput = PAD_INPUT_UP;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::SHOT].padInput = PAD_INPUT_1;
	this->inputButtonState[PLAYER::PLAYER_1][INPUTBUTTON::BOM].padInput = PAD_INPUT_2;


	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::DOWN].keyCode = KEY_INPUT_K;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::LEFT].keyCode = KEY_INPUT_J;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::RIGHT].keyCode = KEY_INPUT_L;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::UP].keyCode = KEY_INPUT_I;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::SHOT].keyCode = KEY_INPUT_B;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::BOM].keyCode = KEY_INPUT_N;

	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::DOWN].padInput = PAD_INPUT_DOWN;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::LEFT].padInput = PAD_INPUT_LEFT;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::RIGHT].padInput = PAD_INPUT_RIGHT;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::UP].padInput = PAD_INPUT_UP;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::SHOT].padInput = PAD_INPUT_1;
	this->inputButtonState[PLAYER::PLAYER_2][INPUTBUTTON::BOM].padInput = PAD_INPUT_2;
}

// ���͏��̍X�V
void Input::update() {
	// �S�ẴL�[�̓��͏�Ԃ��擾
	char keys[Define::KEY_MAX];
	DxLib::GetHitKeyStateAll(keys);
	// �S�ẴL�[�ɂ��Ē��ׂ�
	for (int i = 0; i < Define::KEY_MAX; i++) {
		if (keys[i] == 1) {
			// ���̃L�[��������Ă���
			if (this->keyReleaseCount[i] > 0)this->keyReleaseCount[i] = 0;
			this->keyPresseCount[i]++;
		}
		else {
			// ���̃L�[��������Ă��Ȃ�
			if (this->keyPresseCount[i] > 0)this->keyPresseCount[i] = 0;
			this->keyReleaseCount[i]++;
		}
	}

	// �Q�[���p�b�h�̓��͏�Ԃ��擾
	//if (this->padNum >= 1) {
	for(int i=0;i<Define::PLAYER_MAX;i++){
		int pad = DxLib::GetJoypadInputState(i+1);
		for (int j = 0; j < Define::INPUT_BUTTON_MAX; j++) {
			// �L�[�{�[�h�ƃQ�[���p�b�h�Е��ł����͂���Ă���ƁC���͏�ԂƔ���
			if (this->keyPresseCount[this->inputButtonState[i][j].keyCode] >= 1 || (pad & this->inputButtonState[i][j].padInput)) {
				if (this->inputButtonState[i][j].releaseCount > 0)this->inputButtonState[i][j].releaseCount = 0;
				this->inputButtonState[i][j].pressCount++;
			}
			else {
				if (this->inputButtonState[i][j].pressCount > 0)this->inputButtonState[i][j].pressCount = 0;
				this->inputButtonState[i][j].releaseCount++;
			}
		}
	}

#ifdef _DEBUG
	// �f�o�b�N��:���͏���\��
	for (int i = 0; i < Define::KEY_MAX; i++) {
		if (this->keyPresseCount[i] >= 1) {
			printfDx("%d:%d ", i, this->keyPresseCount[i]);
		}
	}
	printfDx("\n");

	for (int i = 0; i < Define::PLAYER_MAX; i++) {
		for (int j = 0; j < Define::INPUT_BUTTON_MAX; j++) {
			if (this->inputButtonState[i][j].pressCount >= 1) {
				printfDx("P%d-%d:%d ", i + 1, j, this->inputButtonState[i][j].pressCount);
			}
		}
	}
#endif
}

// �w��̃L�[��������Ă��邩���擾
bool Input::getKey(int key) const {
	return this->keyPresseCount[key] > 0;
}

// �w��̃L�[�������ꂽ�u�Ԃ����擾
bool Input::getKeyDown(int key)const {
	return this->keyPresseCount[key] == 1;
}

// ������Ă����w��̃L�[�������ꂽ�u�Ԃ����擾
bool Input::getKeyUp(int key) const {
	return this->keyReleaseCount[key] == 1;
}

// �{�^���������ꂽ�u�Ԃ�����
bool Input::getButtonDown(PLAYER player, INPUTBUTTON button)const {
	return this->inputButtonState[player][button].pressCount == 1;
}

// �{�^���������ꂽ�u�Ԃ�����
bool Input::getButtonUp(PLAYER player, INPUTBUTTON button)const {
	return this->inputButtonState[player][button].releaseCount == 1;
}

// �{�^����������Ă��邩����
bool Input::getButton(PLAYER player, INPUTBUTTON button)const {
	return this->inputButtonState[player][button].pressCount >= 1;
}