#pragma once

#include "Broadcaster.h"
#include "KeyboardInput.h"
#include "MouseInput.h"

#define INPUT_INSTANCE InputManager::GetInstance()

class InputManager
{
private:
	InputManager(void);
	static InputManager* m_instance;

	KeyboardInput* keyboardInput;
	MouseInput* mouseInput;

public:
	void Update();

	static InputManager* GetInstance();

	~InputManager(void);
};

