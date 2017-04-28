#include "precompiled.h"
#include "MouseInput.h"

MouseInput::MouseInput(){

}

void MouseInput::Update(){
	if(GetAsyncKeyState(VK_LBUTTON)){
		POINT mousePosition;
		GetCursorPos(&mousePosition);
		MouseEvent event(VK_LBUTTON, mousePosition.x, mousePosition.y);
		BROADCASTER->NotifyAll(&event);
	}
}

MouseInput::~MouseInput(){

}
