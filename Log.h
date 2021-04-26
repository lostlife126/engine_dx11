#pragma once

#include <clocale>
#include <ctime>

#include <string>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace MyEngine
{

	class Log
	{
	public:
		Log();
		~Log();

		static Log* Get() { return m_instance; }

		void Print(const char* message, ...);
		void Debug(const char* message, ...);
		void Error(const char* message, ...);

	private:
		static Log* m_instance;

		void m_init();
		void m_close();
		void m_print(const char* levtext, const char* text);

		FILE* m_file;
	};

}