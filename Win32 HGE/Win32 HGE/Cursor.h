#pragma once
#include "Input.h"
#include "Entity.h"

class Cursor : public Entity
{
private:
	Input* input;

public:
	Cursor(double, double, Input*);

	void Init() override;

	void Update() override;
	void Render() override;

	void Destroy() override;

	~Cursor(void);
};

