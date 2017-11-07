#include "Resource.h"

int Resource::getResource(RESOURCE_TYPE type, std::string fileName) {
	// 既に読み込み済みのリソースか確認
	for (auto resourceHandle : this->resourceList) {
		if (resourceHandle->fileName == fileName) {
			return resourceHandle->handle;
		}
	}

	// まだ読み込みを行っていないリソースなら,新しく読み込む
	this->resourceList.push_back(new ResourceHandle(type, fileName));
	return this->resourceList.back()->handle;
}