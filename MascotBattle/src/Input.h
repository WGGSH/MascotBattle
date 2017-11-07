#pragma once
#include "Singleton.h"
#include "Define.h"

// �Q�[�����{�^��
enum INPUTBUTTON {
	DOWN,LEFT,RIGHT,UP,
	SHOT,BOM,
};

// �v���C���[�ԍ�
enum PLAYER {
	PLAYER_1,PLAYER_2,
};

// ���̓{�^�����
struct InputButtonState {
	int pressCount; // ����������ꂽ����
	int releaseCount; // �����ꑱ��������
	int keyCode; // �Ή�����L�[�{�[�h
	int padInput; // �Ή�����Q�[���p�b�h�̃{�^��
};

// Input�N���X
class Input final : public Singleton<Input> {
	Input() = default;
	friend Singleton<Input>;
private:
	int padNum; // �p�b�h�̓��͐�
	int keyPresseCount[Define::KEY_MAX]; // �L�[�����͂��ꑱ�����t���[����
	int keyReleaseCount[Define::KEY_MAX]; // �L�[�������ꑱ�����t���[����

	InputButtonState inputButtonState[Define::PLAYER_MAX][Define::INPUT_BUTTON_MAX]; // �Q�[�����{�^���̓��͏��

	int inputButtonPressCount[Define::INPUT_BUTTON_MAX]; // �Q�[�����{�^���̓��͂��ꑱ�����t���[����
	int inputButtonReleaseCount[Define::INPUT_BUTTON_MAX]; // �Q�[�����{�^���̗����ꑱ�����t���[����

public:
	void setup(); // ����������
	void update(); // �X�V

	bool getKey(int)const; // ������Ă��邩����
	bool getKeyDown(int)const; // �����ꂽ�u�Ԃ�����
	bool getKeyUp(int)const; // �b���ꂽ�u�Ԃ�����

	bool getButtonDown(PLAYER, INPUTBUTTON) const; // �{�^���������ꂽ�u�Ԃ�����
	bool getButtonUp(PLAYER, INPUTBUTTON)const; // �{�^���������ꂽ�u�Ԃ�����
	bool getButton(PLAYER, INPUTBUTTON)const; // �{�^����������Ă��邩����
};