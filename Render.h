#pragma once


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "macros.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#ifdef _DEBUG
#	pragma comment(lib, "d3dx11d.lib")
#else
#	pragma comment(lib, "d3dx11.lib")
#endif

namespace MyEngine
{
	//------------------------------------------------------------------

	class Render
	{
	public:
		Render();
		virtual ~Render();

		bool CreateDevice(HWND hwnd);
		void BeginFrame();
		void EndFrame();
		void Shutdown();

		virtual bool Init(HWND hwnd) = 0;
		virtual bool Draw() = 0;
		virtual void Close() = 0;

	protected:
		HRESULT m_compileshaderfromfile(const wchar_t* FileName, LPCSTR EntryPoint, LPCSTR ShaderModel, ID3DBlob** ppBlobOut);

		D3D_DRIVER_TYPE m_driverType;
		D3D_FEATURE_LEVEL m_featureLevel;
		ID3D11Device* m_pd3dDevice;
		ID3D11DeviceContext* m_pImmediateContext;
		IDXGISwapChain* m_pSwapChain;
		ID3D11RenderTargetView* m_pRenderTargetView;

		ID3D11Texture2D* m_pDepthStencil;
		ID3D11DepthStencilView* m_pDepthStencilView;
	};

	//------------------------------------------------------------------
}