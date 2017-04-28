#pragma once

#include "IGameState.h"
#include "GetToPreviousStateEvent.h"
#include "GameAppFramework.h"

class Options : public IGameState
{
private:

public:
	Options::Options(void);

	void Update() override;
	void Render() override;

	void HandleKeyboardEvent(KeyEvent*) override;
	void HandleMouseEvent(MouseEvent*) override;

	void ChangeGameStateTo(IGameState::State) override;
	void LoadResources() override;
	std::vector<std::string> GetResourceVector() override;

	void OnNotify(IEvent*) override;

	Options::~Options();
};