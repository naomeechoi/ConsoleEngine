#pragma once

#include "Level/Level.h"
#include "Math/Color.h"
#include <vector>

using namespace Wanted;

// 메뉴 아이템 구조체
struct MenuItem
{
	using OnSelected = void(*)();

	MenuItem(const char* text, OnSelected onSelected)
		:onSelected(onSelected)
	{
		size_t len = strlen(text) + 1;
		this->text = new char[len];
		strcpy_s(this->text, len, text);
	}

	~MenuItem()
	{
		if (text)
		{
			delete[] text;
			text = nullptr;
		}
	}

	char* text = nullptr;
	OnSelected onSelected = nullptr;
};

class MenuLevel : public Level
{
	RTTI_DECLARATIONS(MenuLevel, Level);

public:
	MenuLevel();
	~MenuLevel();

	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;

private:
	int currentIndex = 0;

	// 선택된 아이템의 색상
	Color selectedColor = Color::Green;

	// 선택되지 않은 아이템 색상
	Color unselectedColor = Color::White;

	std::vector<MenuItem*> items;
};

