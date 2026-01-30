#pragma once

#include "Util/Util.h"
#include <iostream>
#include <vector>

namespace Wanted
{
	// DLL 내부에서만 사용하도록
	class Renderer
	{
	public:
		// 그리기 함수
		static void Draw(const char image)
		{
			std::cout << image;
		}

		// 위치 및 그리기 한번에 처리하는 함수
		static void Draw(const Vector2& position, const char image)
		{
			Util::SetConsolePosition(position);
			Draw(image);
		}

		// 위치 색상 및 그리기
		static void Draw(const Vector2& position, Color color, const char image)
		{
			Util::SetConsolePosition(position);
			Util::SetConsoleTextColor(color);
			Draw(image);

			Util::SetConsoleTextColor(Color::White);
		}
	};
}