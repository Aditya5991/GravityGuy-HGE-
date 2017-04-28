#pragma once

#include "IObject.h"
#include "IListener.h"
#include "MovableEntity.h"
#include "hgerect.h"
#include "Animation.h"

class Player : public MovableEntity, IListener
{
private:
	Sprite *_flyingSprite;
	int _direction;
	std::vector<Animation*> _animations;

public:
	enum AnimationIndex{
		ANIMATION_RUNNING_INDEX,
		ANIMATION_FALLING_INDEX,
	};

	enum MovementState
	{
		MOVEMENT_RUNNING,
		MOVEMENT_FALLING
	};
	MovementState _movementState;

	Player(double, double);

	void Init() override;

	void Update() override;
	void Render() override;

	void Move(double, double);
	void OnNotify(IEvent*) override;
	void Register() override;

	void HandleKeyboardEvent(KeyEvent*);

	void SetMovementState(MovementState);

	void Destroy() override;

	~Player();
};
