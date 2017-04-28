#include "precompiled.h"
#include "EventIdentifier.h"

EventIdentifier* EventIdentifier::m_instance = 0;

EventIdentifier::EventIdentifier(void){
}

KeyEvent* EventIdentifier::IsAKeyEvent(IEvent* event){
	return dynamic_cast<KeyEvent*>(event);
}

MouseEvent* EventIdentifier::IsAMouseEvent(IEvent* event){
	return dynamic_cast<MouseEvent*>(event);
}

GameStateChangeEvent* EventIdentifier::IsAGameStateChangeEvent(IEvent* event){
	return dynamic_cast<GameStateChangeEvent*>(event);
}

GetToPreviousStateEvent* EventIdentifier::IsAGetToPreviousStateEvent(IEvent* event){
	return dynamic_cast<GetToPreviousStateEvent*>(event);
}

GoalScoredEvent* EventIdentifier::IsAGoalScoredEvent(IEvent* event){
	return dynamic_cast<GoalScoredEvent*>(event);
}

EventIdentifier* EventIdentifier::GetInstance(){
	if(m_instance == NULL)
		m_instance = new EventIdentifier();
	return m_instance;
}

EventIdentifier::~EventIdentifier(void){}
