#pragma once
#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h"

class SokobanLevel : public Wanted::Level, public ICanPlayerMove
{
    RTTI_DECLARATIONS(SokobanLevel, Level)

public:
	SokobanLevel();

    virtual void Draw() override;

private:
    // 게임에서 사용할 맵을 로드하는 함수
    void LoadMap(const char* fileName);

    // ICanPlayerMove을(를) 통해 상속됨
    virtual bool CanMove(const Vector2& playerPos, const Vector2& nextPos) override;

    bool CheckGameClear();

private:
    // 획득해야하는 목표 점수
    int targetScore = 0;
    bool isGameClear = false;
};

