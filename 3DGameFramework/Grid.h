#pragma once

#include <Windows.h>
#include <Effects.h>
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <d3d.h>
#include <SimpleMath.h>
#include <DirectXColors.h>

//--------------------------------------------------------------------------------------
//　グリッド描画クラス
//--------------------------------------------------------------------------------------
class Grid
{
private:
	// エフェクト
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;

	// プリミティブバッチ
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_primitiveBatch;

	// インプットレイアウト
	ID3D11InputLayout* m_pInputLayout;

	// グリッド描画エリアの幅と高さと格子のサイズ
	int m_width, m_height, m_size;

	// オフセット
	int m_offx, m_offy;

public:
	// コンストラクタ
	Grid(int width, int height, int size);

	// デストラクタ
	~Grid();

	// 描画
	void Render();

	// グリッドのサイズを設定する関数
	void SetGripInfo(int width, int height, int size)
	{
		m_width = width;
		m_height = height;
		m_size = size;
	}

	// オフセットの設定
	void SetOffset(int offx, int offy)
	{
		m_offx = offx;
		m_offy = offy;
	}
};

//--------------------------------------------------------------------------------------
//　グリッド状の床描画クラス
//--------------------------------------------------------------------------------------
class GridFloor
{
private:
	// エフェクト
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;

	// プリミティブバッチ
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_primitiveBatch;

	// インプットレイアウト
	ID3D11InputLayout* m_pInputLayout;

	// コモンステートへのポインタ
	

	// 床の一辺のサイズ
	float m_size;

	// 分割数
	int m_divs;

public:
	// コンストラクタ (床の一辺のサイズ、一辺の分割数)
	GridFloor(float size,int divs, DirectX::CommonStates);

	// デストラクタ
	~GridFloor();

	// 描画 (ビュー行列、射影行列)
	void Render(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj, DirectX::GXMVECTOR color = DirectX::Colors::Gray);
};