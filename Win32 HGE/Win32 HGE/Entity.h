#pragma once

#include "IObject.h"
#include "Force.h"
#include "Sprite.h"
#include "hgeFont.h"
#include "hgerect.h"
#include "Texture.h"

class Entity : public IObject
{
protected:
	double _x;
	double _y;
	int _width;
	int _height;
	hgeRect* _rect;
	hgeFont *_font;

public:
	Entity(double, double);

	void Init() override;

	virtual	void LoadSprite(Texture, int, int, int, int);
	virtual void Update() override;
	virtual void Render() override;

	void ApplyForce(double, double);
	double GetX();
	double GetY();
	int GetWidth();
	int GetHeight();
	hgeRect* GetRectangle();
	bool TestPoint(float x, float y);

	void SetXY(double x, double y);

	void SetFont(hgeFont*);

	void Destroy();

	~Entity(void);
};

