#pragma once

#include "Engine/Engine.h"
#include <vector>

using namespace Wanted;

enum class State
{
	GamePlay = 0,
	Menu = 1,
	Length,
};

class Game : public Wanted::Engine
{
public:
	Game();
	~Game();

	void ToggleMenu();
	static Game& Get();

private:
	std::vector<Level*> levels;

	State state = State::GamePlay;

	static Game* instance;
};

