#pragma once

#include "KeyEvent.h"
#include "Entity.h"
#include "EventIdentifier.h"
#include "Utils.h"
#include "Timer.h"
#include "Texture.h"

class MovableEntity : public Entity
{
protected:
	double _initX, _initY;
	double _velX;
	double _velY;
	double _velocity;
	Force * _force;

public:
	MovableEntity *_next, *_prev;

public:
	MovableEntity(double, double);

	void Init();

	virtual void UpdateGoalScoredAnimation();
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnNotify(IEvent*);
	virtual void Reset();
	virtual void Move(double, double);

	void LoadSprite(Texture, int, int, int, int);
	double GetVelX();
	double GetVelY();
	virtual double GetVelocity();
	void SetVelX(double velX);
	void SetVelY(double velY);
	void SetForce(double, double);
	Force* GetForce();

	void Destroy();

	~MovableEntity(void);
};

