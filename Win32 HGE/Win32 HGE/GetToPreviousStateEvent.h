#pragma once

#include "IGameState.h"

class GetToPreviousStateEvent : public IEvent
{
public:
	GetToPreviousStateEvent(void);

	~GetToPreviousStateEvent(void) override;
};