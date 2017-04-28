#pragma once

#include "IEvent.h"

class PlayerOutOfBoundsEvent : public IEvent
{
public:
	PlayerOutOfBoundsEvent(void);
	~PlayerOutOfBoundsEvent(void);
};
