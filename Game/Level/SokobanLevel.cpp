#include "SokobanLevel.h"
#include "Actor/Player.h"
#include "Actor/Wall.h"
#include "Actor/Box.h"
#include "Actor/Ground.h"
#include "Actor/Target.h"
#include "Util/Util.h"

#include <iostream>

/*
#: 벽
.: 바닥
p: 플레이어
b: 박스
t: 타겟
*/
SokobanLevel::SokobanLevel()
{
	//AddNewActor(new Player());
	LoadMap("Map.txt");
}

void SokobanLevel::Draw()
{
	super::Draw();

	if (isGameClear)
	{
		Util::SetConsolePosition(Vector2(30, 0));
		Util::SetConsoleTextColor(Color::White);
		std::cout << "Game Clear" << std::endl;
	}
}

void SokobanLevel::LoadMap(const char* fileName)
{
	// 파일 로드
	char path[2048] = {};
	sprintf_s(path, 2048, "../Assets/%s", fileName);

	// 파일 열기
	FILE* file = nullptr;
	fopen_s(&file, path, "rt");

	// 예외 처리
	if (!file)
	{
		std::cerr << "Faild to open map file.\n";
		__debugbreak();
	}

	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);
	// 맵 읽기
	char* data = new char[fileSize + 1];
	size_t readSize = fread(data, sizeof(char), fileSize, file);
	
	// 읽어온 문자열을 이용해 파싱
	int idx = -1;

	Wanted::Vector2 position = Vector2::Zero;

	while (true)
	{
		idx++;
		if (idx >= readSize)
			break;

		char mapChar = data[idx];

		position.x++;
		if (mapChar == '\n')
		{
			position.y++;
			position.x = 0;
			continue;
		}

		switch (mapChar)
		{
		case '1':
		case '#':
			AddNewActor(new Wall(position));
			break;
		
		case '.':
			AddNewActor(new Ground(position));
			break;

		case 'p':
			AddNewActor(new Player(position));
			AddNewActor(new Ground(position));
			break;

		case 'b':
			AddNewActor(new Box(position));
			AddNewActor(new Ground(position));
			break;

		case 't':
			targetScore++;
			AddNewActor(new Target(position));
			break;
		}
	}

	// TEST: 읽어온 데이터 임시로 출력
	//std::cout << data;
	delete[] data;
	fclose(file);
}

bool SokobanLevel::CanMove(const Vector2& playerPos, const Vector2& nextPos)
{
	// 레벨에 있는 박스 액터 모으기
	// 박스는 플레이어가 밀기 등 추가적으로 처리해야 함
	std::vector<Actor*> boxes;
	for (Actor* const actor : actors)
	{
		if (actor->IsTypeOf<Box>())
		{
			boxes.emplace_back(actor);
			continue;
		}
	}

	// 이동하려는 위치에 박스가 있는지 확인
	Actor* boxActor = nullptr;
	for (Actor* const box : boxes)
	{
		if (box->GetPosition() == nextPos)
		{
			boxActor = box;
			break;
		}
	}

	// 이동하려는 곳에 박스가 있는 경우
	if (boxActor)
	{
		// 두 위치 사이에서 이동 방향 구하기
		Vector2 direction = nextPos - playerPos;
		Vector2 nextBoxPos = nextPos + direction;

		for (Actor* const actor : actors)
		{
			if (actor == boxActor)
				continue;

			if (actor->GetPosition() == nextBoxPos)
			{
				if(actor->IsTypeOf<Box>() || actor->IsTypeOf<Wall>())
				return false;
			}
		}

		boxActor->SetPosition(nextBoxPos);
	}

	// 이동하려는 곳에 박스가 없는 경우
	for (Actor* const actor : actors)
	{
		if (actor->GetPosition() == nextPos)
		{
			if (actor->IsTypeOf<Wall>())
			{
				return false;
			}
			break;
		}
	}


	// 점수체크
	isGameClear = CheckGameClear();

	return true;
}

bool SokobanLevel::CheckGameClear()
{
	std::vector<Actor*> boxes;
	std::vector<Actor*> targets;
	for (Actor* const actor : actors)
	{
		if (actor->IsTypeOf<Box>())
		{
			boxes.emplace_back(actor);
		}
		else if (actor->IsTypeOf<Target>())
		{
			targets.emplace_back(actor);
		}
	}

	int count = 0;
	for (Actor* const box : boxes)
	{
		for (Actor* const target : targets)
		{
			if (box->GetPosition() == target->GetPosition())
				count++;
		}
	}
	return targetScore == count;
}
