#pragma once

#include "../BaseScene.h"
class InGame : public BaseScene {
private:
public:
	InGame();
	virtual ~InGame();

	void initialize() override;
	bool update() override;
	void draw()const override;
};
