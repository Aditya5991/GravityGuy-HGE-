#pragma once
#include "hgeSprite.h"
#include "hge.h"

class Loader
{
private:
	HGE* hge;
public:
	Loader(HGE*);

	hgeSprite* loadSprite(char*, int, int, int, int);

	~Loader(void);
};

