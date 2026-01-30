#pragma once

#include "Math/Vector2.h"
#include "Math/Color.h"

using namespace Wanted;

namespace Util
{
	inline void SetConsolePosition(const Vector2& position)
	{
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			static_cast<COORD>(position));
	}

	inline void SetConsoleTextColor(Color color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<unsigned short>(color));
	}

	inline void SetCursorVisible(bool bVisible)
	{
		CONSOLE_CURSOR_INFO info = {};
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		info.bVisible = bVisible;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}
}

