#pragma once

#include "Ball.h"
#include "Math.h"
#include "Player1.h"
#include "Player2.h"
#include "Force.h"

class CollisionManager
{
private:
	Player1 * m_player1;
	Player2 * m_player2;
	Ball* m_ball;
public:
	CollisionManager(Ball*, Player1*, Player2*);

	void CheckCollision(MovableEntity*, MovableEntity*);
	void CheckCollisionBetweenPlayers();
	void CheckCollisionWithBall();
	void Update();

	~CollisionManager(void);
};

