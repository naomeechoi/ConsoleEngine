#pragma once
#include "Common/Common.h"
#include <string>

namespace Wanted
{
	class Input;
	class Renderer;

	class NAOMI_API Engine
	{
		struct EngineSetting
		{
			float framerate = 0.0f;

			int width = 0;
			int height = 0;
		};

	public:
		Engine();
		virtual ~Engine();

		// 엔진 루프
		void Run();
		void QuitEngine();

		// 새 레벨 추가 함수
		void SetNewLevel(class Level* newLevel);

		static Engine& Get();

	protected:
		// 정리 함수
		void Shutdown();

		// 설정 파일 로드 함수
		void LoadSetting();
		std::string trim(const std::string& str);

		void BeginPlay();
		void Tick(float deletaTime);
		void Draw();
		void PostProcess();

	private:
		void SetCursor(bool bOn);

	protected:
		// 엔진 종료 플래그.
		bool isQuit = false;

		// 엔진 설정 값.
		EngineSetting setting;

		// 입력 관리자.
		Input* input = nullptr;
		Renderer* renderer = nullptr;

		// 메인 레벨.
		class Level* mainLevel = nullptr;

		static Engine* instance;
	};
}

