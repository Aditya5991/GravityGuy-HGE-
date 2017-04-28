#pragma once

#include "IGameState.h"
#include "GameAppFramework.h"
#include "Game.h"
#include "EventIdentifier.h"
#include "Player.h"

class GameRunning : public IGameState
{
private:
	Game  *_game;

public:
	GameRunning(void);

	void Update() override;
	void Render() override;
	void StartGame();

	void HandleKeyboardEvent(KeyEvent*) override;
	void HandleMouseEvent(MouseEvent*) override;

	void ChangeGameStateTo(IGameState::State) override;
	void LoadResources() override;
	std::vector<std::string> GetResourceVector() override;

	void OnNotify(IEvent*) override;

	~GameRunning(void);
};

