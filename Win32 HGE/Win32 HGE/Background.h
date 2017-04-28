#pragma once

#include "Entity.h"

class Background : public Entity
{
private:

public:
	Background(void);

	void Update() override;
	void Render() override;

	~Background(void);
};
