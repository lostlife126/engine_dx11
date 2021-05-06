#pragma once
#include "InputCodes.h"
#include "log.h"

//#include <clocale>
//#include <ctime>

//#include <string>
#include <list>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <xnamath.h>
namespace MyEngine
{
	//------------------------------------------------------------------

		// ������� ����
	struct MouseEvent
	{
		MouseEvent(int nx, int ny) : x(nx), y(ny) {}

		// ���������� ����
		int x;
		int y;
	};

	// ������� ������� ������ ����
	struct MouseEventClick : public MouseEvent
	{
		MouseEventClick(eMouseKeyCodes b, int nx, int ny) : MouseEvent(nx, ny), btn(b) {}

		const eMouseKeyCodes btn;	// �������
	};

	// ������� ��������� ����
	struct MouseEventWheel : public MouseEvent
	{
		MouseEventWheel(int nwheel, int nx, int ny) : MouseEvent(nx, ny), wheel(nwheel) {}

		int wheel;
	};

	// ������� �������
	struct KeyEvent
	{
		KeyEvent(wchar_t c, eKeyCodes kc) : wc(c), code(kc) {}

		const wchar_t wc;
		const eKeyCodes code;
	};

	class InputListener
	{
	public:
		// ���� ������ ��������� true - ������� ������ ����� �� ��������������

		// ������ ������
		virtual bool MousePressed(const MouseEventClick& arg) { return false; }
		// ������ ��������
		virtual bool MouseReleased(const MouseEventClick& arg) { return false; }
		// �������� ��������
		virtual bool MouseWheel(const MouseEventWheel& arg) { return false; }
		// �������� ����
		virtual bool MouseMove(const MouseEvent& arg) { return false; }

		// ������ ������
		virtual bool KeyPressed(const KeyEvent& arg) { return false; }
		// ������ ��������
		virtual bool KeyReleased(const KeyEvent& arg) { return false; }
	};

	//------------------------------------------------------------------



class InputMgr
{
public:
	void Init();
	void Close();

	void Run(const UINT& msg, WPARAM wParam, LPARAM lParam);

	void AddListener(InputListener* Listener);

	// ���� ����
	void SetWinRect(const RECT& winrect);

private:
	// ������� �������� ����
	void m_eventcursor();
	// ������� ������ ����
	void m_eventmouse(const eMouseKeyCodes KeyCode, bool press);
	// ������� �������� ��������
	void m_mousewheel(short Value);
	// ��������� ������� �������
	void m_eventkey(const eKeyCodes KeyCode, const wchar_t ch, bool press);

	std::list<InputListener*> m_Listener;

	RECT m_windowrect;
	int m_curx;
	int m_cury;
	int m_MouseWheel;
};

//------------------------------------------------------------------

class MyInputCamera : public InputListener
{
public:

	XMMATRIX* pView;

	void setView(XMMATRIX* pview)
	{
		pView = pview;
	}

	bool KeyPressed(const KeyEvent& arg)
	{
		printf("key press %c\n", arg.wc);
		if (arg.wc == 'e')
			//	printf("BOOOW\n");
		{
			XMMATRIX mSpin = XMMatrixRotationY(-0.1);
			(*pView) = (*pView) * mSpin;
			
		}
		if (arg.wc == 'q')
			//	printf("BOOOW\n");
		{
			XMMATRIX mSpin = XMMatrixRotationY(0.1);
			(*pView) = (*pView) * mSpin;
		}
		if (arg.wc == 'w')
			//	printf("BOOOW\n");
		{
			XMMATRIX mTranslate = XMMatrixTranslation(0.0f, 0.0f, -0.1f );
			(*pView) = (*pView) * mTranslate;

		}
		if (arg.wc == 's')
			//	printf("BOOOW\n");
		{
			XMMATRIX mTranslate = XMMatrixTranslation(0.0f, 0.0f, 0.1f );
			(*pView) = (*pView) * mTranslate;
		}
		if (arg.wc == 'a')
			//	printf("BOOOW\n");
		{
			XMMATRIX mTranslate = XMMatrixTranslation(0.1f, 0.0f, 0.0f);
			(*pView) = (*pView) * mTranslate;

		}
		if (arg.wc == 'd')
			//	printf("BOOOW\n");
		{
			XMMATRIX mTranslate = XMMatrixTranslation(-0.1f, 0.0f, 0.0f);
			(*pView) = (*pView) * mTranslate;
		}
		return false;
	}
	bool MouseMove(const MouseEvent& arg)
	{
		printf("mouse %d - %d\n", arg.x, arg.y);
	//	arg.x = 320;
	//	arg.y = 240;
		return false;
	}

	bool MouseWheel(const MouseEventWheel& arg)
	{
		XMMATRIX mTranslate = XMMatrixTranslation(0.0f, 0.0f, 0.1f * arg.wheel);
		(*pView) = (*pView) * mTranslate;
		return false;
	}
};


}

