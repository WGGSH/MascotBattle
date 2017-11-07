#pragma once

class BaseScene {
private:
public:
	BaseScene() {}
	~BaseScene() {}

	virtual void initialize() = 0;
	virtual bool update() = 0;
	virtual void draw() const = 0;
};
