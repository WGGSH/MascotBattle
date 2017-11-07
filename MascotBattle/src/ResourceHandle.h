#pragma once

#include <string>

enum RESOURCE_TYPE {
	IMAGE = 0,
	MODEL = 1,
	SOUND = 2,
};

struct ResourceHandle {
	int handle;  // DxLibの関数で読み込んだhandle
	RESOURCE_TYPE type; // リソースの種類(画像/モデル/サウンド)
	std::string fileName; // ファイルの名前

	ResourceHandle(RESOURCE_TYPE, std::string);
	~ResourceHandle();
};
