#pragma once

#include "IEvent.h"

class ResourceLoadingCompletedEvent : public IEvent
{
public:
	ResourceLoadingCompletedEvent(void);
	~ResourceLoadingCompletedEvent(void);
};
