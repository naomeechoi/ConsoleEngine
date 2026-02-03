#include "Renderer.h"
#include "ScreenBuffer.h"
#include "Util/Util.h"

namespace Wanted
{
	Renderer* Renderer::instance = nullptr;

	Renderer::Frame::Frame(int bufferCount)
	{
		charInfoArray = new CHAR_INFO[bufferCount];
		memset(charInfoArray, 0, sizeof(CHAR_INFO) * bufferCount);

		sortingOrderArray = new int[bufferCount];
		memset(charInfoArray, 0, sizeof(int) * bufferCount);
	}

	Renderer::Frame::~Frame()
	{
		SafeDeleteArray(charInfoArray);
		SafeDeleteArray(sortingOrderArray);
	}

	void Renderer::Frame::Clear(const Vector2& screenSize)
	{
		const int width = screenSize.x;
		const int height = screenSize.y;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				const int idx = i * width + j;

				CHAR_INFO& info = charInfoArray[idx];
				info.Char.AsciiChar = ' ';
				info.Attributes = 0;
				sortingOrderArray[idx] = -1;
			}
		}
	}

	Renderer::Renderer(const Vector2& screenSize)
		: screenSize(screenSize)
	{
		instance = this;
		const int bufferCount = screenSize.x * screenSize.y;
		frame = new Frame(bufferCount);
		frame->Clear(screenSize);

		screenBuffers[0] = new ScreenBuffer(screenSize);
		screenBuffers[0]->Clear();

		screenBuffers[1] = new ScreenBuffer(screenSize);
		screenBuffers[1]->Clear();

		Present();
	}

	Renderer::~Renderer()
	{
		SafeDelete(frame);
		for (auto*& buffer : screenBuffers)
		{
			SafeDelete(buffer);
		}
	}

	Renderer& Renderer::Get()
	{
		if (!instance)
		{
			MessageBoxA(nullptr, "Renderer::Get() - instance is null", "Error", MB_OK);
			__debugbreak();
		}

		return *instance;
	}

	void Renderer::Draw()
	{

	}

	void Renderer::Submit(
		const char* text,
		const Vector2& position,
		Color color,
		int sortingOrder)
	{
	}

	void Renderer::Clear()
	{

	}

	void Renderer::Present()
	{
	}

	ScreenBuffer* Renderer::GetCurScreenBuffer()
	{
		return nullptr;
	}
}