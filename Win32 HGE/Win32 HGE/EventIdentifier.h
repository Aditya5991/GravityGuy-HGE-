#pragma once

#include "KeyEvent.h"
#include "MouseEvent.h"
#include "GameStateChangeEvent.h"
#include "GetToPreviousStateEvent.h"
#include "GoalScoredEvent.h"

#ifndef EVENT_IDENTIFIER
#define EVENT_IDENTIFIER EventIdentifier::GetInstance()
#endif

class EventIdentifier
{
private:
	EventIdentifier(void);
	static EventIdentifier* m_instance;

public:

	KeyEvent* IsAKeyEvent(IEvent*);
	MouseEvent* IsAMouseEvent(IEvent*);
	GameStateChangeEvent* IsAGameStateChangeEvent(IEvent*);
	GetToPreviousStateEvent* IsAGetToPreviousStateEvent(IEvent*);
	GoalScoredEvent* IsAGoalScoredEvent(IEvent*);

	static EventIdentifier* GetInstance();
	~EventIdentifier(void);
};