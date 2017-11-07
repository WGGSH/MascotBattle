#pragma once

class BaseScene {
private:
public:
	BaseScene() {}
	~BaseScene() {}

	virtual bool update() = 0;
	virtual void draw() const = 0;
};
