#pragma once

#include "IGameState.h"
#include "Entity.h"
#include "FontResource.h"

class PauseGameState : public IGameState
{
private:
	static const int CHOICE_RESUME= 0;
	static const int CHOICE_OPTIONS = 1;
	static const int CHOICE_EXIT = 2;

	static const int MAX_CHOICES = CHOICE_EXIT + 1;

	int m_choice;

	Entity *m_resumeButton, *m_optionsButton, *m_exitButton;
	Sprite *m_cursor;
	Sprite *m_pointer;

	FontResource* m_font;

public:
	PauseGameState();

	void Update();
	void Render();

	void OnNotify(IEvent*) override;

	void HandleKeyboardEvent(KeyEvent*) override;
	void HandleMouseEvent(MouseEvent*) override;

	void LoadResources() override;

	~PauseGameState();
};
