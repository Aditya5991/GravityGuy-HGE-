#pragma once

#include "IListener.h"

class KeyListener : public IListener
{
public:
	virtual void isPressed(IEvent*) = 0;
	virtual void isReleased(IEvent*) = 0;
	virtual void isTyped(IEvent*) = 0;
};