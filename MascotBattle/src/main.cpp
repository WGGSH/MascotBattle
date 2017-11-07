#include "SystemManager.h"
#include "./DxLib.h"


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 初期化処理
	if (SystemManager::Instance()->initialize() == false)return -1;

	// メインループ 
	SystemManager::Instance()->update();

	// 終了処理
	if (SystemManager::Instance()->finalize() == false)return -1;

	return 0;
}