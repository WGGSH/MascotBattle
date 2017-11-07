#include "SystemManager.h"
#include "Input.h"

#include "./DxLib.h"


// ����������
bool SystemManager::initialize() {
	bool isSuccess = true;

	// DxLib_Init�ȑO�̏���������
	if (DxLib::SetGraphMode(Define::WINDOW_WIDTH, Define::WINDOW_HEIGHT, 32) == -1)isSuccess = false;
	if (DxLib::SetWindowSizeChangeEnableFlag(TRUE) == -1)isSuccess = false;
	if (DxLib::ChangeWindowMode(TRUE) == -1)isSuccess = false;
	if (this->setWindowScale() == false)isSuccess = false;

	if (DxLib::DxLib_Init() == -1)return false;

	// DxLib_Init�ȍ~�̏���������
	if (DxLib::SetDrawScreen(DX_SCREEN_BACK) == -1)isSuccess = false;

	Input::Instance()->setup();

	return isSuccess;
}

// ���C�����[�v�ɕK�v�ȃv���Z�X����
bool SystemManager::processLoop() {
	bool isSuccess = true;
	if (DxLib::ScreenFlip() == -1)isSuccess = false;
#ifdef _DEBUG
	// �f�o�b�N��:�f�o�b�N�\�����̍폜
	if (DxLib::clsDx() == -1)isSuccess = false;
#endif
	if (DxLib::ClearDrawScreen() == -1)isSuccess = false;
	if (DxLib::ProcessMessage() == -1)isSuccess = false;
	Input::Instance()->update();
	if (Input::Instance()->getKeyDown(KEY_INPUT_ESCAPE))isSuccess = false;

	return isSuccess;
}

// �I������
bool SystemManager::finalize() {
	if (DxLib::DxLib_End() == -1)return false;
	else return true;
}

bool SystemManager::setWindowScale() {
	int maxX, maxY;
	DxLib::GetDisplayMaxResolution(&maxX, &maxY);
	if (static_cast<float>(maxX) / Define::WINDOW_WIDTH >
		static_cast<float>(maxY) / Define::WINDOW_HEIGHT) {
		DxLib::SetWindowSizeExtendRate(static_cast<float>(maxY) / Define::WINDOW_HEIGHT);
	}
	else {
		DxLib::SetWindowSizeExtendRate(static_cast<float>(maxX) / Define::WINDOW_WIDTH);
	}

	return true;
}