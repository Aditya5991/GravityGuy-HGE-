#pragma once

#include "IEvent.h"

class KeyEvent : public IEvent
{
private:
	int m_keyCode;
	bool m_isKeyPressed;
	
public:
	KeyEvent(int, bool);

	int GetKeyCode();
	bool IsKeyPressed();

	~KeyEvent(void) override;
};
