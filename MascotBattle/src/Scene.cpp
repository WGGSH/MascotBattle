#include "Scene.h"

// トップのシーンを更新する
bool Scene::update() {
	if (this->sceneList.empty())return false;
	bool isSceneChange = this->sceneList.back()->update();
	this->sceneList.back()->draw();
	if (isSceneChange==false) {
		this->pop();
	}
	return true;
}

// ポップ
void Scene::pop() {
	this->sceneList.pop_back();
	if (!this->sceneList.empty()) {
		// シーンリストがからでなければ，最上位のシーンを初期化する
		this->sceneList.back()->initialize();
	}
}

// プッシュ
void Scene::push(BaseScene* scene) {
	this->sceneList.push_back(scene);
	this->sceneList.back()->initialize();
}

void Scene::clear() {
	this->sceneList.clear();
}