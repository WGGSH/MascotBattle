#include "./DxLib.h"

#include "Scene.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �V�[���o�^
	Scene::Instance()->push(new Title());

	// ���C�����[�v 
	// while���̏����͌������b60����s�����
	while (true) {
		if (DxLib::ProcessMessage() == -1)break; // �v���Z�X����
		if (DxLib::CheckHitKey(KEY_INPUT_ESCAPE))break; // ESC�L�[�ŃQ�[���I��

		// �E�B���h�E�ɕ\������Ă�����e���폜����
		DxLib::ClearDrawScreen();

		// �������Ƀ��C������ 
		Scene::Instance()->update();

		 // �`����e���E�B���h�E�ɔ��f������
		DxLib::ScreenFlip();

#ifdef _DEBUG
		// �f�o�b�N��:�f�o�b�N�p�̕\�������폜
		DxLib::clsDx();
#endif
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}