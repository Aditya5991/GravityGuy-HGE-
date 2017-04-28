#pragma once

#include "IEvent.h"

class GoalScoredEvent : public IEvent
{
public:
	GoalScoredEvent(void);


	~GoalScoredEvent(void) override;
};