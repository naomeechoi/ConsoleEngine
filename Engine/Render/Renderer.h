#pragma once

#include "Math/Vector2.h"
#include "Math/Color.h"
#include <Windows.h>
#include <vector>

namespace Wanted
{
	class ScreenBuffer;

	class NAOMI_API Renderer
	{
		struct Frame
		{
			Frame(int bufferCount);
			~Frame();

			void Clear(const Vector2& screenSize);
			CHAR_INFO* charInfoArray = nullptr;
			int* sortingOrderArray = nullptr;
		};

		struct RenderCommand
		{
			const char* text = nullptr;
			Vector2 position = Vector2::Zero;
			Color color = Color::White;
			int sortingOrder = 0;
		};

	public:
		// 그리기 함수
		Renderer(const Vector2& screenSize);
		~Renderer();
		void Draw();
		void Submit(const char* text, const Vector2& position, Color color = Color::White, int sortingOrder = 0);
		static Renderer& Get();

	private:
		void Clear();

		// 활성화 버퍼 교환 함수
		void Present();

		ScreenBuffer* GetCurScreenBuffer();
	private:
		Vector2 screenSize = Vector2::Zero;
		Frame* frame = nullptr;
		ScreenBuffer* screenBuffers[2] = {};
		int curBufferIdx = 0;
		std::vector<RenderCommand> renderQueue;

		static Renderer* instance;
	};
}