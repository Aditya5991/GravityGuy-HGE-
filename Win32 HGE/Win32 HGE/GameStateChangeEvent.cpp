#include "precompiled.h"
#include "GameStateChangeEvent.h"

GameStateChangeEvent::GameStateChangeEvent(IGameState::State state){
	m_state = state;
}

IGameState::State GameStateChangeEvent::GetState(){ return m_state; }

GameStateChangeEvent::~GameStateChangeEvent(void){
}

