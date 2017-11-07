#pragma once

#include <vector>
#include "Singleton.h"
#include "ResourceHandle.h"
class Resource : public Singleton<Resource> {
	Resource() = default;
	friend Singleton<Resource>;
private:
	std::vector<ResourceHandle*> resourceList;
public:
	int getResource(RESOURCE_TYPE, std::string);
};
