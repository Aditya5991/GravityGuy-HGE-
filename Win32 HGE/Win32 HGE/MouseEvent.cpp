#include "precompiled.h"
#include "MouseEvent.h"

MouseEvent::MouseEvent(int keyCode, float mouseX, float mouseY){
	m_keyCode = keyCode;
	m_mouseX = mouseX - 325;
	m_mouseY = mouseY - 195;
}

int MouseEvent::GetKeyCode(){ return m_keyCode; }

float MouseEvent::GetMouseX(){ return m_mouseX; }

float MouseEvent::GetMouseY(){ return m_mouseY; }

MouseEvent::~MouseEvent(void){

}