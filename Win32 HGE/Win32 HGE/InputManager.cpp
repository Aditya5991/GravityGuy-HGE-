#include "precompiled.h"
#include "InputManager.h"

InputManager* InputManager::m_instance = 0;

InputManager::InputManager(void){
	keyboardInput = new KeyboardInput();
	mouseInput = new MouseInput();
}

void InputManager::Update(){
	keyboardInput->Update();
	mouseInput->Update();
}

InputManager* InputManager::GetInstance(){
	if(m_instance == NULL)
		m_instance = new InputManager();
	return m_instance;
}

InputManager::~InputManager(void){
}
