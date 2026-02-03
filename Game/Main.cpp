#include <iostream>
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/SokobanLevel.h"

int main()
{
	/*Wanted::Engine engine;
	engine.SetNewLevel(new SokobanLevel());
	engine.Run();*/

	//Game game;
	//game.Run();

	const int width = 4;
	const int height = 4;
	CHAR_INFO charArray[width * height] = {};
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			charArray[j * width + i].Char.AsciiChar = 'P';
			charArray[j * width + i].Attributes = FOREGROUND_GREEN;
		}

	}

	COORD position = {};
	COORD screenSize = { width, height };
	SMALL_RECT writeRegion{
		0, 0, (short)width, (short)height
	};

	// 문자 배열을 한번에 콘솔로 넘겨서 그릴 때 사용하는 함수
	WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), charArray, screenSize, position, &writeRegion);

	//CreateConsoleScreenBuffer()
	//SetConsoleActiveScreenBuffer()
	std::cin.get();
}