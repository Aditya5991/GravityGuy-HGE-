#pragma once

#include <vector>
#include <string>
#include "hgefont.h"
#include "hgerect.h"
#include "Entity.h"
#include "GameStateChangeEvent.h"
#include "FontResource.h"

class Menu : public IGameState
{
private:
	static const int CHOICE_PLAY = 0;
	static const int CHOICE_OPTIONS = 1;
	static const int CHOICE_EXIT = 2;

	static const int MAX_CHOICES = CHOICE_EXIT + 1;

	int _choice;

	Entity *_background;
	hgeRect *_playButton, *_optionsButton, *_exitButton;
	Sprite *_cursor;

public:
	Menu(void);

	void Update() override;
	void Render() override;

	void HandleKeyboardEvent(KeyEvent*) override;
	void HandleMouseEvent(MouseEvent*) override;
	void LoadResources() override;
	std::vector<std::string> GetResourceVector();

	void OnNotify(IEvent*) override;

	~Menu(void);
};

