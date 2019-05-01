#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d11.h>

// �֐��̃v���g�^�C�v�錾
HRESULT Direct3D_InitDevice(HWND hWnd);
HRESULT Direct3D_InitBackBuffer();
void Direct3D_CleanupDevice();

// �O���[�o���ϐ�
extern Microsoft::WRL::ComPtr<ID3D11Device>				g_pd3dDevice;
extern Microsoft::WRL::ComPtr<ID3D11DeviceContext>		g_pImmediateContext;
extern Microsoft::WRL::ComPtr<IDXGISwapChain>			g_pSwapChain;
extern Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	g_pRenderTargetView;
extern Microsoft::WRL::ComPtr<ID3D11Texture2D>			g_pDepthStencil;
extern Microsoft::WRL::ComPtr<ID3D11DepthStencilView>	g_pDepthStencilView;