#pragma once

#include "Sprite.h"
#include "ILevel.h"

class IObject
{
protected:
	Sprite *_sprite;
	unsigned int _ID;

public:

	IObject(void){}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	virtual int GetID(){ return _ID; }
	virtual void SetID(int ID){ _ID = ID; }

	~IObject(void){}
};
