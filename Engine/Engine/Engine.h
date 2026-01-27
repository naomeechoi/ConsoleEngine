#pragma once
#include "Common/Common.h"

namespace Wanted
{
	class NAOMI_API Engine
	{
		struct KeyState
		{
			bool isKeyDown = false;
			bool wasKeyDown = false;
		};

	public:
		Engine();
		~Engine();

		// 엔진 루프
		void Run();
		void QuitEngine();

		// 입력 확인 함수
		bool GetKeyDown(int keyConde);
		bool GetKeyUp(int keyConde);
		bool GetKey(int keyConde);

		// 새 레벨 추가 함수
		void SetNewLevel(class Level* newLevel);

	private:
		void ProcessInput();
		void BeginPlay();
		void Tick(float deletaTime);
		void Draw();

	private:
		// 엔진 종료 플래그.
		bool isQuit = false;

		KeyState keyStates[255] = { };

		class Level* mainLevel = nullptr;
	};
}

