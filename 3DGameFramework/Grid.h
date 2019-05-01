#pragma once

#include <Windows.h>
#include <Effects.h>
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <d3d.h>
#include <SimpleMath.h>
#include <DirectXColors.h>

//--------------------------------------------------------------------------------------
//�@�O���b�h�`��N���X
//--------------------------------------------------------------------------------------
class Grid
{
private:
	// �G�t�F�N�g
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;

	// �v���~�e�B�u�o�b�`
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_primitiveBatch;

	// �C���v�b�g���C�A�E�g
	ID3D11InputLayout* m_pInputLayout;

	// �O���b�h�`��G���A�̕��ƍ����Ɗi�q�̃T�C�Y
	int m_width, m_height, m_size;

	// �I�t�Z�b�g
	int m_offx, m_offy;

public:
	// �R���X�g���N�^
	Grid(int width, int height, int size);

	// �f�X�g���N�^
	~Grid();

	// �`��
	void Render();

	// �O���b�h�̃T�C�Y��ݒ肷��֐�
	void SetGripInfo(int width, int height, int size)
	{
		m_width = width;
		m_height = height;
		m_size = size;
	}

	// �I�t�Z�b�g�̐ݒ�
	void SetOffset(int offx, int offy)
	{
		m_offx = offx;
		m_offy = offy;
	}
};

//--------------------------------------------------------------------------------------
//�@�O���b�h��̏��`��N���X
//--------------------------------------------------------------------------------------
class GridFloor
{
private:
	// �G�t�F�N�g
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;

	// �v���~�e�B�u�o�b�`
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_primitiveBatch;

	// �C���v�b�g���C�A�E�g
	ID3D11InputLayout* m_pInputLayout;

	// �R�����X�e�[�g�ւ̃|�C���^
	

	// ���̈�ӂ̃T�C�Y
	float m_size;

	// ������
	int m_divs;

public:
	// �R���X�g���N�^ (���̈�ӂ̃T�C�Y�A��ӂ̕�����)
	GridFloor(float size,int divs, DirectX::CommonStates);

	// �f�X�g���N�^
	~GridFloor();

	// �`�� (�r���[�s��A�ˉe�s��)
	void Render(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj, DirectX::GXMVECTOR color = DirectX::Colors::Gray);
};