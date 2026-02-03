#include "MenuLevel.h"
#include "Game/Game.h"
#include "Core/Input.h"
#include "Util/Util.h"
#include <iostream>

MenuLevel::MenuLevel()
{
	items.emplace_back(new MenuItem("Resume Game", []() {Game::Get().ToggleMenu(); }));
	items.emplace_back(new MenuItem("Quit Game", []() {Game::Get().QuitEngine(); }));
}

MenuLevel::~MenuLevel() {
	for (MenuItem*& item : items)
	{
		delete item;
		item = nullptr;
	}

	items.clear();
}

void MenuLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	int len = items.size();
	// 입력 처리
	if (Input::Get().GetKeyDown(VK_UP))
	{
		currentIndex = (currentIndex - 1 + len) % len;
	}
	else if (Input::Get().GetKeyDown(VK_DOWN))
	{
		currentIndex = (currentIndex + 1) % len;
	}
	else if (Input::Get().GetKeyDown(VK_RETURN))
	{
		items[currentIndex]->onSelected();
	}
	else if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleMenu();
		currentIndex = 0;
	}
}

void MenuLevel::Draw()
{
	Util::SetConsolePosition(Vector2::Zero);
	Util::SetConsoleTextColor(Color::White);

	std::cout << "Sokoban Game\n\n";
	for (int i = 0; i < items.size(); i++)
	{
		Color textColor = i == currentIndex ? selectedColor : unselectedColor;
		Util::SetConsoleTextColor(textColor);
		std::cout << items[i]->text << std::endl;
	}
}
