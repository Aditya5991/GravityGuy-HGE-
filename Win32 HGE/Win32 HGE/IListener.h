#pragma once

#include "IEvent.h"

class IListener
{
public:
	IListener* next;
	virtual void OnNotify(IEvent*) = 0;
	virtual void Register() = 0;
};
