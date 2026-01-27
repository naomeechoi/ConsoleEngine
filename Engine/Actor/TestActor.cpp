#include "TestActor.h"
#include <iostream>

void TestActor::BeginPlay()
{
	Actor::BeginPlay();
	std::cout << "TestActor::BeginPlay()." << std::endl;
}

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);
	std::cout << "TestActor::Tick(). deltaTime: "
		<< deltaTime << ", FPS: "
		<< (1.0f / deltaTime) << std::endl;
}

void TestActor::Draw()
{
	Actor::Draw();
}
