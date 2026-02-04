#include "Actor.h"
#include "Util/Util.h"
#include "Render/Renderer.h"

#include <iostream>
#include <Windows.h>

namespace Wanted
{
	Actor::Actor(const char* image, const Vector2& position, Color color)
		:position(position), color(color)
	{
		size_t len = strlen(image) + 1;
		this->image = new char[len];
		strcpy_s(this->image, len, image);
	}

	Actor::~Actor()
	{
		SafeDeleteArray(image);
	}

	void Actor::BeginPlay()
	{
		hasBeganPlay = true;
	}

	void Actor::Tick(float deletaTime)
	{

	}

	void Actor::Draw()
	{
		// 렌더러에 데이터 제출
		Renderer::Get().Submit(image, position, color, sortingOrder);
	}

	void Actor::SetPosition(const Vector2& newPosition)
	{
		if (position == newPosition)
			return;

		position = newPosition;
	}
}