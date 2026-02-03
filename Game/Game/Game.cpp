#include "Game.h"
#include "Level/SokobanLevel.h"
#include "Level/MenuLevel.h"
#include <iostream>

Game* Game::instance = nullptr;

Game::Game()
{
	instance = this;
	levels.emplace_back(new SokobanLevel());
	levels.emplace_back(new MenuLevel());

	state = State::GamePlay;
	mainLevel = levels[0];
}

Game::~Game()
{
	mainLevel = nullptr;

	for (Level*& level : levels)
	{
		delete level;
		level = nullptr;
	}

	levels.clear();
}

void Game::ToggleMenu()
{
	system("cls");

	int stateIndex = (int)state;
	int nextState = 1 - stateIndex;
	state = (State)nextState;

	mainLevel = levels[stateIndex];
}


Game& Game::Get()
{
	if (!instance)
	{
		std::cerr << "Game::Get() - instance is null\n";
		__debugbreak();
	}

	return *instance;
}
