#pragma once

#include <string>

enum RESOURCE_TYPE {
	IMAGE = 0,
	MODEL = 1,
	SOUND = 2,
};

struct ResourceHandle {
	int handle;  // DxLib�̊֐��œǂݍ���handle
	RESOURCE_TYPE type; // ���\�[�X�̎��(�摜/���f��/�T�E���h)
	std::string fileName; // �t�@�C���̖��O

	ResourceHandle(RESOURCE_TYPE, std::string);
	~ResourceHandle();
};
