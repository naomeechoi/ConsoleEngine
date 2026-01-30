#include "Actor.h"
#include "Util/Util.h"
#include "Core/Renderer.h"

#include <iostream>
#include <Windows.h>

namespace Wanted
{
	Actor::Actor(const char image, const Vector2& position, Color color)
		:image(image), position(position), color(color)
	{
	}

	Actor::~Actor()
	{
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
		Renderer::Draw(position, color, image);
	}

	void Actor::SetPosition(const Vector2& newPosition)
	{
		Renderer::Draw(position, ' ');
		position = newPosition;
	}
}