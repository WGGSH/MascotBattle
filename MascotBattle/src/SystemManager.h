#pragma once

#include "Singleton.h"
class SystemManager : public Singleton<SystemManager> {
	SystemManager() = default;
	friend Singleton<SystemManager>;
private:
	bool setWindowScale(); // �E�B���h�E�̕\���{����ݒ�
public:
	bool initialize();	// ����������
	bool processLoop();	// ���C�����[�v�ɕK�v�ȃv���Z�X�Ǘ�����
	bool finalize();	// �I������
};
