#pragma once

#include "IEvent.h"

class MouseEvent : public IEvent
{
private:
	int m_keyCode;
	float m_mouseX, m_mouseY;

public:
	MouseEvent(int, float, float);
	int GetKeyCode();
	float GetMouseX();
	float GetMouseY();
	~MouseEvent() override;
};