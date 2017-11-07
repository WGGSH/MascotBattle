#pragma once

#include "Singleton.h"
#include "ResourceHandle.h"
#include <vector>
class Resource : public Singleton<Resource> {
	Resource() = default;
	friend Singleton<Resource>;
private:
	std::vector<ResourceHandle*> resourceList;
public:
	int getResource(RESOURCE_TYPE, std::string);
};
