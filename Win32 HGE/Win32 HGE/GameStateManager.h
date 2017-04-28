#pragma once

#include <stack>
#include "InputManager.h"
#include "IListener.h"
#include "IGameState.h"

#ifndef GAME_STATE_MANAGER
#define GAME_STATE_MANAGER GameStateManager::GetInstance()
#endif

class GameStateManager : public IListener
{
private:
	GameStateManager(void);

	static GameStateManager* m_instance;
	std::stack<IGameState*> m_states;

public:
	void Update();
	void Render();
	void Push(IGameState*);
	void Pop();

	void OnNotify(IEvent*) override ;
	void Register() override ;

	static GameStateManager* GetInstance();

	~GameStateManager(void);
};

