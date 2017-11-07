#pragma once
#include "Singleton.h"
#include "Define.h"

class Input final : public Singleton<Input> {
	Input() = default;
	friend Singleton<Input>;
private:
	int keyPresseCount[Define::KEY_MAX]; // �L�[�����͂��ꑱ�����t���[����
	int keyReleaseCount[Define::KEY_MAX]; // �L�[�������ꑱ�����t���[����

public:
	void update(); // �X�V

	bool getKey(int)const; // ������Ă��邩����
	bool getKeyDown(int)const; // �����ꂽ�u�Ԃ�����
	bool getKeyUp(int)const; // �b���ꂽ�u�Ԃ�����

};