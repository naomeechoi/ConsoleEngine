#pragma once
#include "Common/Common.h"

namespace Wanted
{
	class NAOMI_API Actor
	{
	public:
		Actor();
		virtual ~Actor();

		virtual void BeginPlay();
		virtual void Tick(float deletaTime);
		virtual void Draw();

		inline bool HasBeganPlay() const { return hasBeganPlay; }
		inline bool IsActive() const { return isActive && !destroyRequested; }
		inline bool DestroyRequested() const { return destroyRequested; }

	protected:
		bool hasBeganPlay = false;
		bool isActive = true;
		bool destroyRequested = false;
	};
}

