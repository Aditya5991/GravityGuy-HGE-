#pragma once

#include "IListener.h"
#include "KeyEvent.h"
#include "hgerect.h"

#ifndef CAMERA
#define CAMERA Camera::GetInstance()
#endif

class Camera
{
private:
	double _x, _y;
	double _xOffset, _yOffset;
	static Camera* _instance;

	Camera(void);

public:
	void Reset();
	void Update();

	double GetX();
	double GetY();
	double GetXOffset();
	double GetYOffset();
	static Camera* GetInstance();

};
