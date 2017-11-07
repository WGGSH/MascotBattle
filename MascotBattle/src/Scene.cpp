#include "Scene.h"

// �g�b�v�̃V�[�����X�V����
bool Scene::update() {
	if (this->sceneList.empty())return false;
	bool isSceneChange = this->sceneList.back()->update();
	this->sceneList.back()->draw();
	if (isSceneChange==false) {
		this->pop();
	}
	return true;
}

// �|�b�v
void Scene::pop() {
	this->sceneList.pop_back();
}

// �v�b�V��
void Scene::push(BaseScene* scene) {
	this->sceneList.push_back(scene);
}

void Scene::clear() {
	this->sceneList.clear();
}