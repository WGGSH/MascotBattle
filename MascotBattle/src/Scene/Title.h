#pragma once

#include "../BaseScene.h"
class Title : public BaseScene {
private:
public:
	Title();
	virtual ~Title();

	void initialize()override;
	bool update() override;
	void draw()const override;
};
