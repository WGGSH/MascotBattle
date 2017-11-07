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
}

// プッシュ
void Scene::push(BaseScene* scene) {
	this->sceneList.push_back(scene);
}

void Scene::clear() {
	this->sceneList.clear();
}