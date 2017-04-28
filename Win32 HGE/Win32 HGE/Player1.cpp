#include "precompiled.h"
#include "Player1.h"

double distance(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

Player1::Player1(double x, double y, Input *input) : MovableEntity(x, y){
	_input = input;
	_accelaration = 0.1;
	_shootPower = 1;
}

void Player1::Init(){

}

void Player1::OnNotify(IEvent* event){
	if(KeyEvent* keyEvent = EVENT_IDENTIFIER->IsAKeyEvent(event)){
		HandleKeyBoardInput(keyEvent);
	}
}

void Player1::HandleKeyBoardInput(KeyEvent* event){
	if(event->GetKeyCode() == VK_SPACE){
		if(event->IsKeyPressed())
			_shootPower = 3;
		else
			_shootPower = 1;
	}
	if(event->GetKeyCode() == VK_CONTROL){
		if(event->IsKeyPressed())
			_accelaration = 0.23;
		else
			_accelaration = 0.1;
	}
	if(event->GetKeyCode() == VK_UP)
		_velY -= _accelaration;
	if(event->GetKeyCode() == VK_DOWN)	
		_velY += _accelaration;
	if(event->GetKeyCode() == VK_LEFT)
		_velX -= _accelaration;
	if(event->GetKeyCode() == VK_RIGHT)
		_velX += _accelaration;
}

void Player1::CheckBounds(){
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

void Player1::Shoot(){
	_shootPower = 3;
}

void Player1::Update(){
	CheckBounds();

	_velX *= 0.97;
	_velY *= 0.97;

	_x += _velX;
	_y += _velY;
}

void Player1::Render(){
	_sprite->Render(_x, _y);
	_font->Render(_x, _y, HGETEXT_TOP, _name);
}

double Player1::GetVelocity(){ 
	return sqrt(_velX*_velX + _velY*_velY)*_shootPower; 
}

double Player1::GetInitX(){ return _initX; }
double Player1::GetInitY(){ return _initY; }

void Player1::SetName(char* name){ _name = name; }

void Player1::Destroy(){

}

Player1::~Player1(void){
}
