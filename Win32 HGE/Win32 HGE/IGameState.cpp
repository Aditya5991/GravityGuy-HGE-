#include "precompiled.h"
#include "IGameState.h"
#include "GameStateChangeEvent.h"
#include "Broadcaster.h"

void IGameState::HandleKeyboardEvent(KeyEvent*){
}

void IGameState::HandleMouseEvent(MouseEvent*){
}

void IGameState::ChangeGameStateTo(IGameState::State newState){
	GameStateChangeEvent event(newState);
	BROADCASTER->NotifyAll(&event);
}

void IGameState::LoadResources(){
}
