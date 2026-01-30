#pragma once
#include "Common/RTTI.h"
#include "Math/Vector2.h"
#include "Math/Color.h"

namespace Wanted
{
	// 전방 선언
	class Level;
	class NAOMI_API Actor : public RTTI
	{
		// RTTI 코드 추가
		RTTI_DECLARATIONS(Actor, RTTI)
	public:
		Actor(const char image = ' ', const Vector2& position = Vector2::Zero, Color color = Color::White);
		virtual ~Actor();

		virtual void BeginPlay();
		virtual void Tick(float deletaTime);
		virtual void Draw();

		// 위치 변경 및 읽기 함수
		void SetPosition(const Vector2& newPosition);
		Vector2 GetPosition() const { return position; }

		// 오너십 추가/읽기 함수
		inline void SetOwner(Level* newOwner) { owner = newOwner; }
		inline Level* GetOwner() const { return owner; }

		inline bool HasBeganPlay() const { return hasBeganPlay; }
		inline bool IsActive() const { return isActive && !destroyRequested; }
		inline bool DestroyRequested() const { return destroyRequested; }

	protected:
		bool hasBeganPlay = false;
		bool isActive = true;
		bool destroyRequested = false;

		char image = ' ';

		Color color = Color::White;

		// 오너십
		Level* owner = nullptr;
	private:
		Vector2 position;
	};
}

