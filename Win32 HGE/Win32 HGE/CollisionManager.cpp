#include "precompiled.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager(Ball* ball, Player1* player, Player2* player2){
	m_ball = ball;
	m_player1 = player;
	m_player2 = player2;
}

void CollisionManager::CheckCollision(MovableEntity *e1, MovableEntity * e2){
	double e1x = e1->GetX() + e1->GetWidth()/2;
	double e1y = e1->GetY() + e1->GetHeight()/2;
	double e2x = e2->GetX() + e2->GetWidth()/2;
	double e2y = e2->GetY() + e2->GetHeight()/2;

	double distance = sqrt((e1x-e2x)*(e1x-e2x) + (e1y-e2y)*(e1y-e2y));

	if(distance < (e1->GetWidth()/2 + e2->GetWidth()/2)){
		double angle = atan2(e1y-e2y, e1x-e2x);
		double vel1 = e1->GetVelocity();
		double vel2 = e2->GetVelocity();

		e1->SetVelX(vel2*cos(angle)*0.8);
		e1->SetVelY(vel2*sin(angle)*0.8);
		e2->SetVelX(-vel1*cos(angle)*0.8);
		e2->SetVelY(-vel1*sin(angle)*0.8);
	}
}

void CollisionManager::CheckCollisionBetweenPlayers(){
	//MovableEntity *entity = m_playerManager->GetList()->GetStart();
	//while(entity->m_next != NULL){
	//	CheckCollision(entity->m_next, entity);
	//	entity = entity->m_next;
	//}
}

void CollisionManager::CheckCollisionWithBall(){
	/*MovableEntity *entity = m_playerManager->GetList()->GetStart();
	while(entity != NULL){

		double ballX  = m_ball->GetX() + m_ball->GetWidth()/2;
		double ballY = m_ball->GetY() + m_ball->GetHeight()/2;
		double entityX = entity->GetX() + entity->GetWidth()/2;
		double entityY = entity->GetY() + entity->GetHeight()/2;

		double distance = sqrt((ballX-entityX)*(ballX-entityX) + (ballY - entityY)*(ballY - entityY));

		if(distance < (m_ball->GetWidth()/2 + entity->GetWidth()/2)){
			double angle = atan2(ballY - entityY, ballX - entityX);
			double ballVelocity = m_ball->GetVelocity();
			double entityVelocity = entity->GetVelocity();
			m_ball->SetVelX(entityVelocity*cos(angle));
			m_ball->SetVelY(entityVelocity*sin(angle));
			//entity->setVelX(entity->getVelX() * 0.5);
			//entity->setVelY(entity->getVelY() * 0.5);
		}

		entity = entity->m_next;
	}*/

	double ballX  = m_ball->GetX() + m_ball->GetWidth()/2;
	double ballY = m_ball->GetY() + m_ball->GetHeight()/2;
	double playerX = m_player1->GetX() + m_player1->GetWidth()/2;
	double playerY = m_player1->GetY() + m_player1->GetHeight()/2;

	double distance = sqrt((ballX-playerX)*(ballX-playerX) + (ballY - playerY)*(ballY - playerY));

	if(distance < (m_ball->GetWidth()/2 + m_player1->GetWidth()/2)){
		double angle = atan2(ballY - playerY, ballX - playerX);
		double ballVelocity = m_ball->GetVelocity();
		double playerVelocity = m_player1->GetVelocity();
		m_ball->SetVelX(playerVelocity*cos(angle));
		m_ball->SetVelY(playerVelocity*sin(angle));
		//entity->setVelX(entity->getVelX() * 0.5);
		//entity->setVelY(entity->getVelY() * 0.5);
	}

	double player2X = m_player2->GetX() + m_player2->GetWidth()/2;
	double player2Y = m_player2->GetY() + m_player2->GetHeight()/2;

	distance = sqrt((ballX-player2X)*(ballX-player2X) + (ballY - player2Y)*(ballY - player2Y));

	if(distance < (m_ball->GetWidth()/2 + m_player2->GetWidth()/2)){
		double angle = atan2(ballY - player2Y, ballX - player2X);
		double ballVelocity = m_ball->GetVelocity();
		double playerVelocity = m_player2->GetVelocity();
		m_ball->SetVelX(playerVelocity*cos(angle));
		m_ball->SetVelY(playerVelocity*sin(angle));
		//entity->setVelX(entity->getVelX() * 0.5);
		//entity->setVelY(entity->getVelY() * 0.5);
	}

}

void CollisionManager::Update(){
	CheckCollisionWithBall();
	CheckCollisionBetweenPlayers();
}

CollisionManager::~CollisionManager(void){
}
