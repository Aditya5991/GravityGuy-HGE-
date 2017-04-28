#pragma once

#include "Ball.h"
#include "Broadcaster.h"
#include "GoalScoredEvent.h"
#include "FontResource.h"
#include <string>

class ScoreManager
{
private:
	int m_scoreTeam1;
	int m_scoreTeam2;
	bool m_goalScored;
	Entity *m_ball;
	FontResource *m_font;

	std::string m_strScoreTeam1;
	std::string m_strScoreTeam2;

private:
	bool IsBetween(double, double, double);

public:
	ScoreManager(Entity*);

	void Update();
	void Render(hgeFont*);
	bool IsGoalScored();
	void ChangeGoalScoredState();

	~ScoreManager(void);
};

