// ===== ===== ===== ===== ===== ===== ===== =====
// @file	WinMain.cpp
// @brief	�G���g���|�C���g
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ���g�p�����̌x���΍�
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(nCmdShow);

	// �f�o�b�O���p���O�t�@�C���̏o�̗͂}��
	SetOutApplicationLogValidFlag(FALSE);

	ChangeWindowMode(TRUE);	          // �E�C���h�E���[�h�Ŏ��s

	std::string windowTitle = Game::TITLE + "    " + Game::VERSION;
	SetMainWindowText(windowTitle.c_str());    // �E�C���h�E�^�C�g���̐ݒ�
//	SetWindowIconID(IDI_ICON1);       // �E�C���h�E�A�C�R���̐ݒ�

	// ������Ԃ̉�ʃ��[�h�̐ݒ�
	SetGraphMode(1280, 720, 32);

	// DX���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}

	// �`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->Initialize();

	game->Execute();

	game->Finalize();

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}