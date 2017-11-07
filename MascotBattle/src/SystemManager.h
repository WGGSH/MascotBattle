#pragma once

#include "Singleton.h"
class SystemManager : public Singleton<SystemManager> {
	SystemManager() = default;
	friend Singleton<SystemManager>;
private:
	bool setWindowScale(); // �E�B���h�E�̕\���{����ݒ�
	bool processLoop();	// ���C�����[�v�ɕK�v�ȃv���Z�X�Ǘ�����
public:
	bool initialize();	// ����������
	bool update(); // ���C�����[�v
	bool finalize();	// �I������
};
