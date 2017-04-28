#pragma once

#include "Entity.h"
#include "Animation.h"

class Coin : public Entity
{
private:
	Animation* _animation;

public:
	Coin(double, double);

	void Init() override;

	void Update() override;
	void Render() override;

	void Destroy() override;

	~Coin(void);
};
