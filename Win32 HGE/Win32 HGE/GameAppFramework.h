#pragma once
#include "hgesprite.h"

#ifndef HGE_INSTANCE
#define HGE_INSTANCE GameAppFramework::GetInstance()->getHGE()
#endif

#include "InputManager.h"
#include "GameStateManager.h"

class GameAppFramework
{
private:
	hgeSprite *_cursor;

	GameAppFramework();
	static GameAppFramework *m_instance;
	HGE* m_hge;

public:
	void init();

	static bool HGEUpdateCallback();
	static bool HGERenderCallback();

	void StartGame();
	void EndGame();

	bool Update();
	bool Render();

	HGE* getHGE();
	static GameAppFramework* GetInstance();

	~GameAppFramework(void);
};
