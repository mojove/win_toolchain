[!if RIBBON_TOOLBAR]
// ���� MFC �T���v�� �\�[�X �R�[�h�ł́AMFC Microsoft Office Fluent ���[�U�[ �C���^�[�t�F�C�X 
// ("Fluent UI") �̎g�p���@�������܂��B���̃R�[�h�́AMFC C++ ���C�u���� �\�t�g�E�F�A�� 
// ��������Ă��� Microsoft Foundation Class ���t�@�����X����ъ֘A�d�q�h�L�������g��
// �⊮���邽�߂̎Q�l�����Ƃ��Ē񋟂���܂��B
// Fluent UI �𕡐��A�g�p�A�܂��͔z�z���邽�߂̃��C�Z���X�����͌ʂɗp�ӂ���Ă��܂��B
// Fluent UI ���C�Z���X �v���O�����̏ڍׂɂ��ẮAWeb �T�C�g
// http://go.microsoft.com/fwlink/?LinkId=238214 ���Q�Ƃ��Ă��������B
//
// Copyright (C) Microsoft Corporation
// All rights reserved.
[!endif]

// [!output DIALOG_AUTO_PROXY_IMPL] : �����t�@�C��
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output DIALOG_AUTO_PROXY_HEADER]"
#include "[!output DIALOG_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output DIALOG_AUTO_PROXY_CLASS]

IMPLEMENT_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])

[!output DIALOG_AUTO_PROXY_CLASS]::[!output DIALOG_AUTO_PROXY_CLASS]()
{
	EnableAutomation();
	
	// �I�[�g���[�V���� �I�u�W�F�N�g���A�N�e�B�u�ł������A�A�v���P�[�V������ 
	//	���s��Ԃɂ��Ă��������A�R���X�g���N�^�[�� AfxOleLockApp ���Ăяo���܂��B
	AfxOleLockApp();

	// �A�v���P�[�V�����̃��C�� �E�B���h�E �|�C���^�[���Ƃ����ă_�C�A���O
	//  �փA�N�Z�X���܂��B�v���L�V�̓����|�C���^�[����_�C�A���O�ւ̃|�C
	//  ���^��ݒ肵�A�_�C�A���O�̖߂�|�C���^�[�����̃v���L�V�֐ݒ肵��
	//  ���B
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF([!output DIALOG_CLASS], AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS([!output DIALOG_CLASS])))
		{
			m_pDialog = reinterpret_cast<[!output DIALOG_CLASS]*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

[!output DIALOG_AUTO_PROXY_CLASS]::~[!output DIALOG_AUTO_PROXY_CLASS]()
{
	// ���ׂẴI�u�W�F�N�g���I�[�g���[�V�����ō쐬���ꂽ�ꍇ�ɃA�v���P�[�V����
	//	���I�����邽�߂ɁA�f�X�g���N�^�[�� AfxOleUnlockApp ���Ăяo���܂��B
	//  ���̏����̊ԂɁA���C�� �_�C�A���O��j�󂵂܂��B
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void [!output DIALOG_AUTO_PROXY_CLASS]::OnFinalRelease()
{
	// �I�[�g���[�V���� �I�u�W�F�N�g�ɑ΂���Ō�̎Q�Ƃ���������Ƃ���
	// OnFinalRelease ���Ăяo����܂��B���N���X�͎����I�ɃI�u�W�F�N�g��
	// �폜���܂��B�ǉ��̃N���[���A�b�v���K�v�ł�
	// �ʂȌ㏈����ǉ����Ă��������B

	[!output DIALOG_AUTO_PROXY_BASE_CLASS]::OnFinalRelease();
}

BEGIN_MESSAGE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_DISPATCH_MAP()

// ����: VBA ����^�C�v �Z�[�t�ȃo�C���h���T�|�[�g���邽�߂ɁAIID_I[!output SAFE_PROJECT_IDENTIFIER_NAME] �̃T�|�[�g��ǉ����܂��B
//  ���� IID �́A.IDL �t�@�C���̃f�B�X�p�b�` �C���^�[�t�F�C�X�փA�^�b�`����� 
//  GUID �ƈ�v���Ȃ���΂Ȃ�܂���B

// {[!output DISPIID_REGISTRY_FORMAT]}
static const IID IID_I[!output SAFE_PROJECT_IDENTIFIER_NAME] =
[!output DISPIID_STATIC_CONST_GUID_FORMAT];

BEGIN_INTERFACE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
	INTERFACE_PART([!output DIALOG_AUTO_PROXY_CLASS], IID_I[!output SAFE_PROJECT_IDENTIFIER_NAME], Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 �}�N�����A���̃v���W�F�N�g�� StdAfx.h �Œ�`����܂��B
// {[!output APP_CLSID_REGISTRY_FORMAT]}
IMPLEMENT_OLECREATE2([!output DIALOG_AUTO_PROXY_CLASS], "[!output SAFE_PROJECT_IDENTIFIER_NAME].Application", [!output APP_CLSID_IMPLEMENT_OLECREATE_FORMAT])


// [!output DIALOG_AUTO_PROXY_CLASS] ���b�Z�[�W �n���h���[