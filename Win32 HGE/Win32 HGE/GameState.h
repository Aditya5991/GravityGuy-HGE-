#pragma once

#include "hge.h"

class GameState{

protected:
	HGE* hge;

public:
	GameState(HGE*);

	virtual void update() = 0;
	virtual void render() = 0;

	~GameState();
};