#include "ResourceHandle.h"

#include "./DxLib.h"

ResourceHandle::ResourceHandle(RESOURCE_TYPE _type, std::string _fileName) :
	type(_type), fileName(_fileName) ,handle(0){

	// 読み込むファイルの種類に応じたロード関数を実行
	switch (this->type) {
	case RESOURCE_TYPE::IMAGE:
		this->handle = DxLib::LoadGraph(this->fileName.c_str());
		break;
	case RESOURCE_TYPE::MODEL:
		this->handle = DxLib::MV1LoadModel(this->fileName.c_str());
		break;
	case RESOURCE_TYPE::SOUND:
		this->handle = DxLib::LoadSoundMem(this->fileName.c_str());
		break;
	default:
		break;
	}
}

ResourceHandle::~ResourceHandle() {
	// 読み込んだリソースを種類に応じて開放する
	switch (this->type) {
	case RESOURCE_TYPE::IMAGE:
		DxLib::DeleteGraph(this->handle);
		break;
	case RESOURCE_TYPE::MODEL:
		DxLib::MV1DeleteModel(this->handle);
		break;
	case RESOURCE_TYPE::SOUND:
		DxLib::DeleteSoundMem(this->handle);
		break;
	default:
		break;
	}
}