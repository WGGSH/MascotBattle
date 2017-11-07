#include "Scene.h"

void Scene::update() {
	bool isSceneChange = (*this->sceneList.begin())->update();
	(*this->sceneList.begin())->draw();
	if (isSceneChange==false) {
		this->pop();
	}
}

void Scene::pop() {
	this->sceneList.erase(this->sceneList.begin());
}

void Scene::push(BaseScene* scene) {
	this->sceneList.push_back(scene);
}