#pragma once

#include "ILevel.h"
#include <fstream>
#include <iostream>

class Level1 : public ILevel
{
public:
	Level1(void);

	void Update() override;
	void Render() override;
	void Load() override;
	void SetOffset(double, double) override;
	
	~Level1(void);
};
