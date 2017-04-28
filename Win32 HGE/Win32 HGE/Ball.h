#pragma once

#include "Utils.h"
#include "MovableEntity.h"

class Ball : public MovableEntity
{
public:
	Ball(double, double);
	
	void Init() override;

	void Update() override;
	void Render() override;

	void OnNotify(IEvent*);

	void CheckBounds();

	void Destroy() override;

	~Ball(void);
};

