#pragma once
#include <clocale>
#include <ctime>

#include <string>
#include <list>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//#include "macros.h"

#include "Window.h"
#include "Render.h"
#include "Input.h"
#include "Log.h"



namespace MyEngine
{
		//------------------------------------------------------------------
	struct FrameworkDesc
	{
		DescWindow wnd;
		Render* render;
	};

	class Engine
	{
	public:
		Engine();
		~Engine();

		bool Init(const FrameworkDesc& desc);
		void Run();
		void Close();

		void SetRender(Render* render) { m_render = render; }
		void AddInputListener(InputListener* listener);
	protected:
		bool m_frame();
		FrameworkDesc m_desc;
		Window* m_wnd;
		Render* m_render;
		InputMgr* m_input;
		Log m_log;
		bool m_init;		// если было инициализировано
	};

		//------------------------------------------------------------------

}