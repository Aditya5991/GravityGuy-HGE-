#pragma once

#include "ITile.h"

class SolidTile : public ITile
{
public:
	SolidTile();

	void Update() override;
	void Render(double, double) override;
	bool IsSolid() override;

	~SolidTile(void);
};
