#pragma once

#include <vector>
#include "Singleton.h"
#include "BaseScene.h"
class Scene : public Singleton<Scene> {
	Scene() = default;
	friend Singleton<Scene>;
private:
	std::vector<BaseScene*> sceneList;
public:
	void pop();
	void clear();
	void push(BaseScene*);
	bool update();
};

#include "Scene/Title.h"
#include "Scene/InGame.h"