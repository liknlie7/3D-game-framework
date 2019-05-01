﻿#ifndef GRIDFLOOR_DEFINED
#define GRIDFLOOR_DEFINED

#include <d3d11_1.h>
#include <algorithm>
#include <wrl/client.h>
#include <DirectXColors.h>
#include <Effects.h>
#include <PrimitiveBatch.h>
#include <memory>
#include <SimpleMath.h>
#include <VertexTypes.h>
#include <CommonStates.h>

class GridFloor
{
	// エフェクト
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;
	// プリミティブバッチ
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_primitiveBatch;
	// インプットレイアウト
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_pInputLayout;
	// コモンステートへのポインタ
	DirectX::CommonStates* m_states;
	// 床の一辺のサイズ
	float m_size;
	// 分割数
	int m_divs;

public:
	// コンストラクタ
	GridFloor(ID3D11Device* device, ID3D11DeviceContext* context, DirectX::CommonStates* states, float size, int divs);
	// デストラクタ
	~GridFloor();
	// 描画する
	void Render(ID3D11DeviceContext* context, DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj, DirectX::GXMVECTOR color = DirectX::Colors::Gray);
};

#endif	// GRIDFLOOR_DEFINED


