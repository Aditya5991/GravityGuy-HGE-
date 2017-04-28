#include "precompiled.h"
#include "Input.h"

Input::Input(int controller){
	this->controller = controller;
	event = new hgeInputEvent();
}

void Input::reset(){ 
	up = down = left = right = ctrl = space = false;
	mouseLeft = mouseMiddle = mouseRight = false;
	mouseDragged = mouseReleased = false;
}

void Input::update(HGE* hge){
	reset();
	if(controller == ARROW_CONTROLLER){
		if(hge->Input_GetKeyState(HGEK_UP)) up = true;
		if(hge->Input_GetKeyState(HGEK_DOWN)) down = true;
		if(hge->Input_GetKeyState(HGEK_LEFT)) left = true;
		if(hge->Input_GetKeyState(HGEK_RIGHT)) right = true;
		if(hge->Input_GetKeyState(HGEK_CTRL)) ctrl = true;
		if(hge->Input_GetKeyState(HGEK_SPACE)) space = true;
	}else{
		if(hge->Input_GetKeyState(HGEK_I)) up = true;
		if(hge->Input_GetKeyState(HGEK_K)) down = true;
		if(hge->Input_GetKeyState(HGEK_J)) left = true;
		if(hge->Input_GetKeyState(HGEK_L)) right = true;
		if(hge->Input_GetKeyState(HGEK_CAPSLOCK)) ctrl = true;
		if(hge->Input_GetKeyState(HGEK_SHIFT)) space = true;
	}

	if(hge->Input_GetKeyState(HGEK_LBUTTON)) mouseLeft = true;
	if(hge->Input_GetKeyState(HGEK_RBUTTON)) mouseRight = true;
	if(hge->Input_GetKeyState(HGEK_MBUTTON)) mouseMiddle = true;

	//if(hge->Input_GetEvent(event)){
	//	if(event->type == INPUT_MBUTTONDOWN){
	//		mouseDragged = true;
	//	}
	//	else if(event->type == INPUT_MBUTTONUP){
	//		mouseReleased = true;
	//	}
	//}

	hge->Input_GetMousePos(&mouseX, &mouseY);
}

float Input::getMouseX(){ return mouseX; }
float Input::getMouseY(){ return mouseY; }

Input::~Input(void){
}
