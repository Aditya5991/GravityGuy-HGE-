#pragma once

#include "IEvent.h"

class LoadResourcesEvent : public IEvent
{
public:
	LoadResourcesEvent::LoadResourcesEvent(void);
	LoadResourcesEvent::~LoadResourcesEvent(void) override;
};
