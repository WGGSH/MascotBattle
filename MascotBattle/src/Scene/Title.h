#pragma once

#include "../BaseScene.h"
class Title : public BaseScene {
private:
public:
	Title();
	virtual ~Title();

	bool update() override;
	void draw()const override;
};
