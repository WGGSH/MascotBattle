#include "SystemManager.h"
#include "Input.h"

#include "./DxLib.h"


// 初期化処理
bool SystemManager::initialize() {
	bool isSuccess = true;

	// DxLib_Init以前の初期化処理
	if (DxLib::SetGraphMode(Define::WINDOW_WIDTH, Define::WINDOW_HEIGHT, 32) == -1)isSuccess = false;
	if (DxLib::SetWindowSizeChangeEnableFlag(TRUE) == -1)isSuccess = false;
	if (DxLib::ChangeWindowMode(TRUE) == -1)isSuccess = false;
	if (this->setWindowScale() == false)isSuccess = false;

	if (DxLib::DxLib_Init() == -1)return false;

	// DxLib_Init以降の初期化処理
	if (DxLib::SetDrawScreen(DX_SCREEN_BACK) == -1)isSuccess = false;

	Input::Instance()->setup();

	return isSuccess;
}

// メインループに必要なプロセス処理
bool SystemManager::processLoop() {
	bool isSuccess = true;
	if (DxLib::ScreenFlip() == -1)isSuccess = false;
#ifdef _DEBUG
	// デバック時:デバック表示情報の削除
	if (DxLib::clsDx() == -1)isSuccess = false;
#endif
	if (DxLib::ClearDrawScreen() == -1)isSuccess = false;
	if (DxLib::ProcessMessage() == -1)isSuccess = false;
	Input::Instance()->update();
	if (Input::Instance()->getKeyDown(KEY_INPUT_ESCAPE))isSuccess = false;

	return isSuccess;
}

// 終了処理
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