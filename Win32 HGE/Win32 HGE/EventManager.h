#pragma once

#include "KeyEvent.h"
#include "MouseEvent.h"

#ifndef EVENT_MANAGER
#define EVENT_MANAGER EventManager::GetInstance()
#endif

class EventManager
{
private:
	KeyEvent* keyEvent;
	MouseEvent* mouseEvent;
	
	EventManager* m_instance;
	EventManager(void);

public:

	void Update();

	EventManager* GetInstance();
};