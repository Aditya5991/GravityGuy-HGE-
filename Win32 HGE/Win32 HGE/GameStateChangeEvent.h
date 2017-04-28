#pragma once

#include "IEvent.h"
#include "IGameState.h"

class GameStateChangeEvent : public IEvent
{
private:
	IGameState::State m_state;

public:
	GameStateChangeEvent(IGameState::State);
		
	IGameState::State GetState();

	~GameStateChangeEvent(void) override;
};