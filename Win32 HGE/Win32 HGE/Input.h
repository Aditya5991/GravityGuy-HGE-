#pragma once

#include "hge.h"

class Input
{
private:
	enum { ARROW_CONTROLLER = 1, IJKL_CONTOLLER };
	hgeInputEvent *event;
	int controller;
public:
	 bool up, down, left, right, ctrl, space;
	 bool mouseLeft, mouseRight, mouseMiddle;
	 bool mouseDragged;
	 bool mouseReleased;
	 float mouseX, mouseY;

public:
	Input(int);

	void reset();
	void update(HGE*);
	float getMouseX();
	float getMouseY();

	~Input(void);

};

