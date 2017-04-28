#pragma once

#include "ITile.h"

class VoidTile : public ITile
{
public:
	VoidTile();

	void Update() override;
	void Render(double, double) override;

	~VoidTile(void);
};
