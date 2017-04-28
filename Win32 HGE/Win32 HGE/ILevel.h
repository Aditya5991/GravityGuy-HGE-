#pragma once

#include "ITile.h"
#include <string>

class ILevel
{
protected:
	int _width;
	int _height;
	std::vector<std::vector<ITile*>> _tiles;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Load()= 0;
	virtual void SetOffset(double, double) = 0;
	virtual ITile* GetTile(int x, int y){ return _tiles[y][x]; }
	virtual ~ILevel(void){}
};
