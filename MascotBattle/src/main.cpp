#include "./DxLib.h"

#include "Scene.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// シーン登録
	Scene::Instance()->push(new Title());

	// メインループ 
	// while内の処理は原則毎秒60回実行される
	while (true) {
		if (DxLib::ProcessMessage() == -1)break; // プロセス処理
		if (DxLib::CheckHitKey(KEY_INPUT_ESCAPE))break; // ESCキーでゲーム終了

		// ウィンドウに表示されている内容を削除する
		DxLib::ClearDrawScreen();

		// ↓ここにメイン処理 
		Scene::Instance()->update();

		 // 描画内容をウィンドウに反映させる
		DxLib::ScreenFlip();

#ifdef _DEBUG
		// デバック時:デバック用の表示情報を削除
		DxLib::clsDx();
#endif
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}