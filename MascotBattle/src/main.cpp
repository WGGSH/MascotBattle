#include "./DxLib.h"

#include "Scene.h"
#include "SystemManager.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ����������
	if (SystemManager::Instance()->initialize() == false)return -1;

	// �V�[���o�^
	Scene::Instance()->push(new Title());

	// ���C�����[�v 
	// while���̏����͌������b60����s�����
	while (SystemManager::Instance()->processLoop()) {
		// �������Ƀ��C������ 
		if (Scene::Instance()->update() == false)break;
	}

	// �I������
	if (SystemManager::Instance()->finalize() == false)return -1;

	return 0;
}