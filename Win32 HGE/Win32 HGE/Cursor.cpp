#include "precompiled.h"
#include "Cursor.h"

Cursor::Cursor(double x, double y, Input* input) : Entity(x, y){
	this->input = input;
}

void Cursor::Init(){

}

void Cursor::Update(){
	_x = input->getMouseX();
	_y = input->getMouseY();
}

void Cursor::Render(){
	_sprite->Render(_x, _y);
}

void Cursor::Destroy(){

}

Cursor::~Cursor(void){
}
