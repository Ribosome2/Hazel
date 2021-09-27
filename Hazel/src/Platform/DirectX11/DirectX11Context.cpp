#include "hzpch.h"
#include "DirectX11Context.h"

#define _WIN32_WINNT 0x600
#include <stdio.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include "GLFW/glfw3.h"

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")
namespace Hazel {

	DirectX11Context::DirectX11Context(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void DirectX11Context::Init()
	{
		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = 640;
		sd.BufferDesc.Height = 480;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow =(HWND) m_WindowHandle;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		HRESULT  D3D11CreateDeviceAndSwapChain(
			IDXGIAdapter * pAdapter,
			D3D_DRIVER_TYPE            DriverType,
			HMODULE                    Software,
			UINT                       Flags,
			const D3D_FEATURE_LEVEL * pFeatureLevels,
			UINT                       FeatureLevels,
			UINT                       SDKVersion,
			const DXGI_SWAP_CHAIN_DESC * pSwapChainDesc,
			IDXGISwapChain * *ppSwapChain,
			ID3D11Device * *ppDevice,
			D3D_FEATURE_LEVEL * pFeatureLevel,
			ID3D11DeviceContext * *ppImmediateContext
		);
		
		glfwMakeContextCurrent(m_WindowHandle);
	}

	void DirectX11Context::SwapBuffers()
	{
		
	}
}

