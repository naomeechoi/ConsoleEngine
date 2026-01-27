#include "Level.h"
#include "Actor/Actor.h"

namespace Wanted
{
	Level::Level()
	{
	}

	Level::~Level()
	{
		for (Actor*& actor : actors)
		{
			if (!actor)
				continue;

			delete actor;
			actor = nullptr;
		}

		actors.clear();
	}

	void Level::BeginPlay()
	{
		for (Actor* actor : actors)
		{
			if (actor->HasBeganPlay())
				continue;

			actor->BeginPlay();
		}
	}

	void Level::Tick(float deletaTime)
	{
		for (Actor* actor : actors)
		{
			actor->Tick(deletaTime);
		}
	}

	void Level::Draw()
	{
		for (Actor* actor : actors)
		{
			actor->Draw();
		}
	}
	
	void Level::AddNewActor(Actor* newActor)
	{
		// TODO: 나중에 프레임 처리 고려해서 따로 추가 작업 해야함
		actors.emplace_back(newActor);
	}
}