#pragma once

#include "Timer.h"
#include "IEvent.h"
#include "EventIdentifier.h"

#include "Ball.h"
#include "PlayerManager.h"
#include "CollisionManager.h"
#include "Player1.h"
#include "Player2.h"
#include "Cursor.h"
#include "Field.h"
#include "GoalPost.h"
#include "ScoreManager.h"
#include "Loader.h"

class Game
{
public:
	static const int WIDTH = 1280;
	static const int HEIGHT = 720;

protected:
	HGE* m_hge;
	PlayerManager *m_player_manager;
	Player1* m_player1;
	Player2* m_player2;
	CollisionManager *m_collisionManager;
	Ball *m_ball;
	Input *m_input1;
	Input *m_input2;
	Loader* m_loader;
	Entity* m_cursor;
	Entity* m_field;
	Entity* m_leftGoalPost;
	Entity* m_rightGoalPost;
	ScoreManager* m_scoreManager;

	hgeFont *font;

private:

	Timer *timer;

	enum GameState {
		RUNNING,
		GOAL_SCORED_ANIMATION,
		PAUSE
	};

	GameState m_currentState;

	void ResetAll();
	void InitCursor();
	void InitBall();
	void InitPlayerManager();
	void InitField();
	void InitGoalPosts();
	void InitScoreManager();
	void InitCollisionManager();

public:
	Game(HGE*);

	void Init();
	void UpdateGoalScoredAnimationState();
	void UpdateRunningState();
	void Update();
	void Render();

	void OnNotify(IEvent*);

	~Game(void);
};

