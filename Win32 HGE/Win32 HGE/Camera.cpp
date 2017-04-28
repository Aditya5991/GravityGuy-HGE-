#include "precompiled.h"
#include "Camera.h"
#include "Broadcaster.h"

Camera* Camera::_instance = 0;

Camera::Camera(void){
	_xOffset = 4;
	_yOffset = 0;
	_x = _y = 0;
}

void Camera::Reset(){
	_xOffset = 4;
	_yOffset = 0;
	_x = _y = 0;
}

void Camera::Update(){
	_x += _xOffset;
}

double Camera::GetX(){ return _x; }
double Camera::GetY(){ return _y; }
double Camera::GetXOffset(){ return _xOffset; }
double Camera::GetYOffset(){ return _yOffset; }

Camera* Camera::GetInstance(){
	if(_instance == NULL)
		_instance = new Camera();
	return _instance;
}