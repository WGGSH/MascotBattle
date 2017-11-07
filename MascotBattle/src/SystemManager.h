#pragma once

#include "Singleton.h"
class SystemManager : public Singleton<SystemManager> {
	SystemManager() = default;
	friend Singleton<SystemManager>;
private:
	bool setWindowScale(); // ウィンドウの表示倍率を設定
	bool processLoop();	// メインループに必要なプロセス管理処理
public:
	bool initialize();	// 初期化処理
	bool update(); // メインループ
	bool finalize();	// 終了処理
};
