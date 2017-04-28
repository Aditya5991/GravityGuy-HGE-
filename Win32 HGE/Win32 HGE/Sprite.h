#pragma once

#include "hgeSprite.h"
#include "hge.h"
#include "IResource.h"

class Sprite
{
private:
	double _x, _y;
	double _width, _height;
	hgeSprite *_sprite;
	hgeRect* _rectangle;

public:
	Sprite(HTEXTURE, int, int, int , int);
	Sprite(IResource*, int, int, int , int);
	Sprite(int, int, int);

	void Update(double, double);
	void Render(double, double);
	void RenderStretch(double, double, double, double);
	void RenderEx(double, double, double, double, double);
	void Set(double, double);
	void Flip();
	int GetWidth();
	int GetHeight();
	hgeRect* GetRectangle();

	~Sprite(void);
};

