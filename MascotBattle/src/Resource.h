#pragma once

#include <vector>
#include "Singleton.h"
class Resource : public Singleton<Resource> {
	Resource() = default;
	friend Singleton<Resource>;
private:

public:
};
