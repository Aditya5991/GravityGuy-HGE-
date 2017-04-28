#include "precompiled.h"
#include "ScoreManager.h"
#include "ResourceManager.h"

ScoreManager::ScoreManager(Entity* ball){
	m_ball = ball;
	m_scoreTeam1 = m_scoreTeam2 = 0;
	m_goalScored = false;

	m_strScoreTeam1 = "Team1 : " + std::to_string(m_scoreTeam1);
	m_strScoreTeam2 = "Team2 : " + std::to_string(m_scoreTeam2);

	m_font = dynamic_cast<FontResource*>(RESOURCE_MANAGER->GetResource("font1.fnt"));
}

bool ScoreManager::IsBetween(double value, double lower, double upper){
	return ((value>=lower) && (value <= upper));
}

void ScoreManager::Update(){
	if(m_ball->GetX() < constants::FieldXmin){
		if(IsBetween(m_ball->GetY(), constants::leftGoalPostTop, constants::leftGoalPostBottom)){
			m_scoreTeam2++;
			m_goalScored = true;
			GoalScoredEvent event;
			BROADCASTER->NotifyAll(&event);
		}
		m_strScoreTeam1 = "Team1 : " + std::to_string(m_scoreTeam1);
		m_strScoreTeam2 = "Team2 : " + std::to_string(m_scoreTeam2);
	}

	if(m_ball->GetX() + m_ball->GetWidth() > constants::FieldXmax){
		if(IsBetween(m_ball->GetY(), constants::rightGoalPostTop, constants::rightGoalPostBottom)){
			m_scoreTeam1++;
			m_goalScored = true;
			GoalScoredEvent event;
			BROADCASTER->NotifyAll(&event);
		}
		m_strScoreTeam1 = "Team1 : " + std::to_string(m_scoreTeam1);
		m_strScoreTeam2 = "Team2 : " + std::to_string(m_scoreTeam2);
	}
}

void ScoreManager::Render(hgeFont* font){
	m_font->Render(5, 5, m_strScoreTeam1);
	m_font->Render(1280-150, 5, m_strScoreTeam2);
}

bool ScoreManager::IsGoalScored(){ return m_goalScored; }
void ScoreManager::ChangeGoalScoredState(){ m_goalScored = !m_goalScored; }

ScoreManager::~ScoreManager(void){
}
