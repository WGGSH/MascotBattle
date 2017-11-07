#include "SystemManager.h"
#include "./DxLib.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ����������
	if (SystemManager::Instance()->initialize() == false)return -1;

	// ���C�����[�v 
	SystemManager::Instance()->update();

	// �I������
	if (SystemManager::Instance()->finalize() == false)return -1;

	return 0;
}