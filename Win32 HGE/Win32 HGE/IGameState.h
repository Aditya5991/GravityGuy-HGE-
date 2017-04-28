#pragma once

#include <vector>
#include <string>
#include "KeyEvent.h"
#include "MouseEvent.h"

class IGameState{

protected:
	std::vector<std::string> _resources;

public:

	enum State{
		LOADING_STATE,
		MENU_STATE,
		GAME_RUNNING_STATE,
		OPTIONS_STATE,
		PAUSE_GAME_STATE,
	};

	virtual void Update() = 0;
	virtual void Render() = 0;
	
	virtual void HandleKeyboardEvent(KeyEvent*);
	virtual void HandleMouseEvent(MouseEvent*);
	
	virtual void ChangeGameStateTo(IGameState::State);
	virtual void LoadResources();
	virtual std::vector<std::string> GetResourceVector(){ return _resources; }
	
	virtual void OnNotify(IEvent*) = 0;
}; 