#pragma once

#include <list>
#include "Input.h"
#include "MovableEntity.h"
#include "Math.h"
#include "EntityList.h"

class Player2 : public MovableEntity
{
private:
	Input *_input;
	double _accelaration;
	double _shootPower;
	char* _name;

public:
	Player2(double, double, Input*);

	void OnNotify(IEvent*);

	void Init() override;
	void HandleKeyBoardInput(KeyEvent*);
	void HandleMouseInput();
	void Shoot();
	void CheckBounds();

	void Update() override;
	void Render() override;

	double GetVelocity();
	double GetInitX();
	double GetInitY();
	void SetName(char*);
	void Destroy() override;

	~Player2(void);
};

