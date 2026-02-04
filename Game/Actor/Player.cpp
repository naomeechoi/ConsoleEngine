#include "Player.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include "Actor/Box.h"
#include "Level/Level.h"

#include "Game/Game.h"

#include "Interface/ICanPlayerMove.h"

#include <iostream>
#include <Windows.h>

Player::Player(const Vector2& position)
	: super("P", position, Color::Yellow)
{
	sortingOrder = 10;
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	Actor::BeginPlay();
}

void Player::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	if (Wanted::Input::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleMenu();
		return;
	}

	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		Wanted::Engine::Get().QuitEngine();
	}
	/*std::cout << "TestActor::Tick(). deltaTime: "
		<< deltaTime << ", FPS: "
		<< (1.0f / deltaTime) << std::endl;*/

	// 인터페이스 확인
	static ICanPlayerMove* canMoveInterface = nullptr;
	if(!canMoveInterface && GetOwner())
		canMoveInterface = dynamic_cast<ICanPlayerMove*>(GetOwner());
	
	Vector2 newPosition = GetPosition();
	bool isMove = false;

	if (Wanted::Input::Get().GetKeyDown(VK_RIGHT) && GetPosition().x < 20)
	{
		isMove = true;
		newPosition.x += 1;
	}
	else if (Wanted::Input::Get().GetKeyDown(VK_LEFT) && GetPosition().x > 0)
	{
		isMove = true;
		newPosition.x -= 1;
	}
	else if (Wanted::Input::Get().GetKeyDown(VK_UP) && GetPosition().y > 0)
	{
		isMove = true;
		newPosition.y -= 1;
	}
	else if (Wanted::Input::Get().GetKeyDown(VK_DOWN) && GetPosition().y < 20)
	{
		isMove = true;
		newPosition.y += 1;
	}

	if(canMoveInterface->CanMove(GetPosition(), newPosition) && isMove)
		SetPosition(newPosition);
}

void Player::Draw()
{
	Actor::Draw();
}
