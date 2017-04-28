#pragma once

#include "KeyEvent.h"
#include "Broadcaster.h"

#define MAX_KEYS		256

class KeyboardInput{
private:
	bool *keys;

	void Reset();

public:
	KeyboardInput(void);
	
	void Update();
	void HandleKeyPressed();
	void HandleKeyReleased();

	void HandleAlphabetsPressed();
	void HandleAlphabetsReleased();
	void HandleNumericCharactersPressed();
	void HandleNumericCharactersReleased();

 	~KeyboardInput(void);
};