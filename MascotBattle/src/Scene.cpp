#include "Scene.h"

void Scene::update() {
	bool isSceneChange = (*this->sceneList.begin())->update();
	(*this->sceneList.begin())->draw();
	if (isSceneChange==false) {
		this->pop();
	}
}

void Scene::pop() {
	this->sceneList.pop_back();
}

void Scene::push(BaseScene* scene) {
	this->sceneList.push_back(scene);
}