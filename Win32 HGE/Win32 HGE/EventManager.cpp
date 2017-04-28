#include "precompiled.h"
#include "EventManager.h"

EventManager::EventManager(){
}

void EventManager::Update(){
}

EventManager* EventManager::GetInstance(){
	if(m_instance == NULL)
		m_instance = new EventManager();
	return m_instance;
}
