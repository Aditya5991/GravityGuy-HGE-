#include "precompiled.h"
#include "Player2.h"

Player2::Player2(double x, double y, Input *input) : MovableEntity(x, y){
	_input = input;
	_accelaration = 0.1;
	_shootPower = 1;
}

void Player2::Init(){

}

void Player2::OnNotify(IEvent* event){
	if(KeyEvent* keyEvent = EVENT_IDENTIFIER->IsAKeyEvent(event)){
		HandleKeyBoardInput(keyEvent);
	}
}

void Player2::HandleKeyBoardInput(KeyEvent* event){
	if(event->GetKeyCode() == VK_INSERT){
		if(event->IsKeyPressed())
			_shootPower = 3;
		else
			_shootPower = 1;
	}
	if(event->GetKeyCode() == VK_HOME){
		if(event->IsKeyPressed())
			_accelaration = 0.23;
		else
			_accelaration = 0.1;
	}	
	if(event->GetKeyCode() == VK_NUMPAD5)
		_velY -= _accelaration;
	if(event->GetKeyCode() == VK_NUMPAD2)	
		_velY += _accelaration;
	if(event->GetKeyCode() == VK_NUMPAD1)
		_velX -= _accelaration;
	if(event->GetKeyCode() == VK_NUMPAD3)
		_velX += _accelaration;
}

void Player2::CheckBounds(){
	if(_x < constants::FieldXmin){
		_velX *= -1;
		_x = constants::FieldXmin;
	}
	if((_x + _width) > constants::FieldXmax){
		_velX *= -1;
		_x =  constants::FieldXmax - _width;
	}

	if(_y < constants::FieldYmin){
		_velY *= -1;
		_y = constants::FieldYmin;
	}
	if((_y + _height) > constants::FieldYmax){
		_velY *= -1;
		_y = constants::FieldYmax - _height;
	}
}

void Player2::Shoot(){
	_shootPower = 3;
}

void Player2::Update(){
	CheckBounds();

	_velX *= 0.97;
	_velY *= 0.97;

	_x += _velX;
	_y += _velY;
}

void Player2::Render(){
	_sprite->Render(_x, _y);
	_font->Render(_x, _y, HGETEXT_TOP, _name);
}

double Player2::GetVelocity(){ 
	return sqrt(_velX*_velX + _velY*_velY)*_shootPower; 
}

double Player2::GetInitX(){ return _initX; }
double Player2::GetInitY(){ return _initY; }

void Player2::SetName(char* name){ _name = name; }

void Player2::Destroy(){

}

Player2::~Player2(void){
}
