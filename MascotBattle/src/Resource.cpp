#include "Resource.h"

int Resource::getResource(RESOURCE_TYPE type, std::string fileName) {
	// ���ɓǂݍ��ݍς݂̃��\�[�X���m�F
	for (auto resourceHandle : this->resourceList) {
		if (resourceHandle->fileName == fileName) {
			return resourceHandle->handle;
		}
	}

	// �܂��ǂݍ��݂��s���Ă��Ȃ����\�[�X�Ȃ�,�V�����ǂݍ���
	this->resourceList.push_back(new ResourceHandle(type, fileName));
	return this->resourceList.back()->handle;
}