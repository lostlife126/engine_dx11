#pragma once
#include <clocale>
#include <ctime>

#include <string>
#include <list>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "macros.h"

#include <d3d11.h>
#include <d3dx11.h>


#pragma comment(lib, "d3d11.lib")
#ifdef _DEBUG
#	pragma comment(lib, "d3dx11d.lib")
#else
#	pragma comment(lib, "d3dx11.lib")
#endif


#include "Window.h"
#include "Render.h"
#include "Input.h"
#include "Log.h"

namespace MyEngine
{
		//------------------------------------------------------------------

	class Engine
	{
	public:
		Engine();
		~Engine();

		bool Init();
		void Run();
		void Close();

		void SetRender(Render* render) { m_render = render; }
		void AddInputListener(InputListener* listener);
	protected:
		bool m_frame();

		Window* m_wnd;
		Render* m_render;
		InputMgr* m_input;
		Log m_log;
		bool m_init;		// если было инициализировано
	};

		//------------------------------------------------------------------

}