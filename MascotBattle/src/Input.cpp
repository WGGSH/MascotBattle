// --- Input.cpp ---
#include "Input.h"
#include "DxLib.h"

// ���͏��̍X�V
void Input::update() {

	// �}�E�X�̓��͏�Ԃ��擾
	if (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) {
		if (this->mouseReleaseCount>0)this->mouseReleaseCount = 0;
		this->mousePressCount++;
	}
	else {
		if (this->mousePressCount>0)this->mousePressCount = 0;
		this->mouseReleaseCount++;
	}

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

#ifdef _DEBUG
	// �f�o�b�N��:���͏���\��
	DxLib::printfDx("%d:%d\n", this->mousePressCount, this->mouseReleaseCount);
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