#include "precompiled.h"
#include "Game.h"
#include "ResourceManager.h"

Game::Game(HGE* hge){
	m_hge = hge;
	m_loader = new Loader(hge);
	m_input1 = new Input(1);
	m_input2 = new Input(2);

	m_currentState = RUNNING;

	timer = new Timer();
}

void Game::Init(){
	font = new hgeFont("font1.fnt");

	InitField();
	InitCursor();
	InitPlayerManager();
	InitBall();
	InitGoalPosts();
	InitScoreManager();
	InitCollisionManager();
}

void Game::InitScoreManager(){
	m_scoreManager = new ScoreManager(m_ball);
}

void Game::InitGoalPosts(){
	//IResource *resource = RESOURCE_MANAGER->GetResource("PlayButton.png");
	//int factor = 0;
	//m_play_sprite = new Entity(400, 100 + 100*factor++);
	//m_play_sprite->LoadSprite(*(dynamic_cast<Texture*>(resource)), 0, 0, 64, 32);

	//resource = RESOURCE_MANAGER->GetResource("OptionsButton.png");
	//m_options = new Entity(400, 100 + 100*factor++);
	//m_options->LoadSprite(*(dynamic_cast<Texture*>(resource)), 0, 0, 64, 32);

	//resource = RESOURCE_MANAGER->GetResource("ExitButton.png");
	//m_exit = new Entity(400, 100 + 100*factor);
	//m_exit->LoadSprite(*(dynamic_cast<Texture*>(resource)), 0, 0, 64, 32);

	m_leftGoalPost = new GoalPost(25, 265);
	m_leftGoalPost->LoadSprite(*(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("LeftGoalPost.jpg"))), 0, 0, 48, 186);

	m_rightGoalPost = new GoalPost(1211, 265);
	m_rightGoalPost->LoadSprite(*(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("RightGoalPost.jpg"))), 0, 0, 48, 186);
}

void Game::InitField(){
	m_field = new Entity(0, 0);
	m_field->LoadSprite(*(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("Field.jpg"))), 0, 0, 1280, 720);
}

void Game::InitCursor(){
	m_cursor = new Cursor(m_input1->getMouseX(), m_input1->getMouseY(), m_input1);
	m_cursor->LoadSprite(*(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("Cursor.png"))), 0, 0, 32, 32);
}

void Game::InitBall(){
	m_ball = new Ball(640 - 16, 360 - 16);
	m_ball->LoadSprite(*(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("Ball.jpg"))), 0, 0, 32, 32);
}

void Game::InitPlayerManager(){
	/*Player *player1 = new Player(178 - 32, 360, m_input1);
	player1->LoadSprite(m_hge->Texture_Load("Player.jpg"), 0, 0, 64, 64);
	player1->SetFont(font);
	player1->SetName("Aditya");

	Player *player2 = new Player(1001 - 32, 360, m_input2);
	player2->LoadSprite(m_hge->Texture_Load("BluePlayer.jpg"), 0, 0, 64, 64);
	player2->SetFont(font);
	player2->SetName("Ganesh");

	m_player_manager = new PlayerManager();
	m_player_manager->Add(player1);
	m_player_manager->Add(player2);*/

	m_player1 = new Player1(278 - 32, 362 - 32, m_input1);
	m_player1->LoadSprite(*(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("RedPlayer.jpg"))), 0, 0, 64, 64);
	m_player1->SetFont(font);
	m_player1->SetName("Aditya");

	m_player2 = new Player2(1000 - 32, 362 - 32, m_input1);
	m_player2->LoadSprite(*(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("BluePlayer.jpg"))), 0, 0, 64, 64);
	m_player2->SetFont(font);
	m_player2->SetName("Ganesh");
}

void Game::InitCollisionManager(){
	m_collisionManager = new CollisionManager(m_ball, m_player1, m_player2);
}

void Game::UpdateGoalScoredAnimationState(){
	m_player1->UpdateGoalScoredAnimation();
	m_player2->UpdateGoalScoredAnimation();
	m_ball->UpdateGoalScoredAnimation();
}

void Game::UpdateRunningState(){
	//m_player_manager->Update(m_hge);
	m_player1->Update();
	m_player2->Update();
	m_ball->Update();
	m_collisionManager->Update();
	m_cursor->Update();
	m_scoreManager->Update();
}

void Game::Update(){
	switch(m_currentState){
	case RUNNING:
		UpdateRunningState();
		break;
	case GOAL_SCORED_ANIMATION:
		if(!timer->IsRunning()){
			timer->Start();
		}
		timer->Update();
		UpdateGoalScoredAnimationState();
		if(timer->CurrentTimeInSeconds() > 2){
			timer->Stop();
			m_currentState = RUNNING;
		}
		break;
	}
}

void Game::Render(){
	m_field->Render();
	m_leftGoalPost->Render();
	m_rightGoalPost->Render();
	//m_player_manager->Render(m_hge);
	m_player1->Render();
	m_player2->Render();
	m_ball->Render();
	m_cursor->Render();
	m_scoreManager->Render(font);
}

void Game::OnNotify(IEvent* event){
	if(KeyEvent* keyEvent = dynamic_cast<KeyEvent*>(event)){
		m_player1->OnNotify(event);
		m_player2->OnNotify(event);
	}
	if(MouseEvent* keyEvent = dynamic_cast<MouseEvent*>(event)){
		m_player1->OnNotify(event);
		m_player2->OnNotify(event);
	}
	if(GoalScoredEvent* goalScoredEvent = EVENT_IDENTIFIER->IsAGoalScoredEvent(event)){
		m_currentState = GOAL_SCORED_ANIMATION;
		//m_player->OnNotify(event);
		//m_ball->OnNotify(event);
	}
}

Game::~Game(void){
}
