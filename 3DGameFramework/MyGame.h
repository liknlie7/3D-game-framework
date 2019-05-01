#pragma once
#ifndef MYGAME_DEFINED
#define MYGAME_DEFINED

#include "Window.h"
#include "Game.h"

class MyGame : public Game 
{
public:
	// �R���X�g���N�^
	MyGame(int width, int height);
	// �Q�[���I�u�W�F�N�g����������
	void Initialize(int width, int height) override;
	// ���\�[�X�𐶐�����
	void CreateResources() override;
	// �Q�[�����X�V����
	void Update(const DX::StepTimer& timer) override;
	// �Q�[����`�悷��
	void Render(const DX::StepTimer& timer) override;
	// �I�������������Ȃ�
	void Finalize() override;

	// FPS��`�悷��
	void DrawFPS(const DX::StepTimer& timer);

private:
	// ��
	int m_width;
	// ����
	int m_height;
	// ���[���h�s��
	DirectX::SimpleMath::Matrix m_world;
	// �r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	// �ˉe�s��
	DirectX::SimpleMath::Matrix m_projection;

	// �X�v���C�g�o�b�`
	DirectX::SpriteBatch* m_spriteBatch;
	// �G�t�F�N�g�t�@�N�g���C���^�[�t�F�[�X(m_fxFactory)
	std::unique_ptr<DirectX::IEffectFactory> m_effectFactory;
	// �R�����X�e�[�g
	std::unique_ptr <DirectX::CommonStates> m_commonStates;
	// ���f��
	std::unique_ptr<DirectX::Model> m_model;

	// DirectX11�N���X�̃C���X�^���X���擾����
	DirectX11& m_directX = DirectX11::Get();
};

#endif	// MYGAME_DEFINED