#pragma once

#include "ILevel.h"
#include "Player.h"

class CollisionLogic
{
private:
	ILevel *_level;
	Player *_player;

public:
	CollisionLogic(ILevel*, Player*);

	void Update();
	void UpdateLevelCollision();
	void UpdateCoinCollision();
	void Render();

	~CollisionLogic(void);
};
