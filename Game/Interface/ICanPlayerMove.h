#pragma once
#include "Math/Vector2.h"

using namespace Wanted;

// 플레이어가 이동할 위치를 판단해주는 인터페이스
class ICanPlayerMove
{
public:
	virtual bool CanMove(const Vector2& playerPos, const Vector2& nextPos) = 0;
};