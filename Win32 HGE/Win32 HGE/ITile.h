#pragma once

#include "Sprite.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "hgerect.h"

class ITile
{
protected:
	hgeRect* _rect;
	Sprite *_sprite;

public:
	ITile(){
	}

	virtual void Update(){}
	virtual void Render(double, double){}
	virtual hgeRect* GetRect(){ return _rect; }
	virtual void SetRect(double x1, double y1, double x2, double y2){ _rect = new hgeRect(x1, y1, x2, y2); }

	virtual bool IsSolid(){ return false; }
};
