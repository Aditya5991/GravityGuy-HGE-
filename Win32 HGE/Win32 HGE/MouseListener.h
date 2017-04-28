#pragma  once

#include "IListener.h"
#include "MouseEvent.h"

class MouseListener : public IListener
{

public:
	virtual void OnClick(MouseEvent*) = 0;
	virtual void OnNotify(IEvent*) = 0;
};