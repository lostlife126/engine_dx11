#include "engine.h"

//#include "macros.h"
#include "Log.h"

namespace MyEngine
{
	//------------------------------------------------------------------

	Engine::Engine() :
		m_wnd(nullptr),
		m_render(nullptr),
		m_input(nullptr),
		m_init(false)
	{
	}

	Engine::~Engine()
	{
	}

	void Engine::AddInputListener(InputListener* listener)
	{
		if (m_input)
			m_input->AddListener(listener);
	}

	void Engine::Run()
	{
		if (m_init)
			while (m_frame());
	}

	bool Engine::Init()
	{
		m_wnd = new Window();
		m_input = new InputMgr();

		if (!m_wnd || !m_input)
		{
			Log::Get()->Error("�� ������� �������� ������");
			return false;
		}

		m_input->Init();

		// ������� �������� �������� �� ���������. � ����� �� ������� ������ �� �������� � �����
		DescWindow desc;
		if (!m_wnd->Create(desc))
		{
			Log::Get()->Error("�� ������� ������� ����");
			return false;
		}
		m_wnd->SetInputMgr(m_input);

		if (!m_render->CreateDevice(m_wnd->GetHWND()))
		{
			Log::Get()->Error("�� ������� ������� ������");
			return false;
		}

		m_init = true;
		return true;
	}

	bool Engine::m_frame()
	{
		// ������������ ������� ����
		m_wnd->RunEvent();
		// ���� ���� ��������� - ��������� ����
		if (!m_wnd->IsActive())
			return true;

		// ���� ���� ���� �������, ��������� ������ ������
		if (m_wnd->IsExit())
			return false;

		// ���� ���� �������� ������
		if (m_wnd->IsResize())
		{

		}

		m_render->BeginFrame();
		if (!m_render->Draw())
			return false;
		m_render->EndFrame();

		return true;
	}

	void Engine::Close()
	{
		m_init = false;
		m_render->Shutdown();
		_DELETE(m_render);
		_CLOSE(m_wnd);
		_CLOSE(m_input);
	}

	//------------------------------------------------------------------
}