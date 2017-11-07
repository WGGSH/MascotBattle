#pragma once

#include "../Scene.h"
class InGame : public BaseScene {
private:
public:
	InGame();
	virtual ~InGame();

	bool update() override;
	void draw()const override;
};
