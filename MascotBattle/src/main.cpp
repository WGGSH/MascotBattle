#include "./DxLib.h"

#include "Scene.h"
#include "SystemManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 初期化処理
	if (SystemManager::Instance()->initialize() == false)return -1;

	// シーン登録
	Scene::Instance()->push(new Title());

	// メインループ 
	// while内の処理は原則毎秒60回実行される
	while (SystemManager::Instance()->processLoop()) {
		// ↓ここにメイン処理 
		if (Scene::Instance()->update() == false)break;
	}

	// 終了処理
	if (SystemManager::Instance()->finalize() == false)return -1;

	return 0;
}