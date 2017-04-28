#include "precompiled.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "GameAppFramework.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	GameAppFramework::GetInstance()->init();
	GameAppFramework::GetInstance()->StartGame();
	GameAppFramework::GetInstance()->EndGame();

	//_CrtDumpMemoryLeaks();  

	return 0;

}
