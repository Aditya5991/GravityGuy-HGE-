#include "precompiled.h"
#include "KeyEvent.h"
#include "Broadcaster.h"

KeyEvent::KeyEvent(int keyCode, bool isKeyPressed){
	m_keyCode = keyCode;
	m_isKeyPressed = isKeyPressed;
}

int KeyEvent::GetKeyCode(){ return m_keyCode; }
bool KeyEvent::IsKeyPressed(){ return m_isKeyPressed; }

KeyEvent::~KeyEvent(void){

}
