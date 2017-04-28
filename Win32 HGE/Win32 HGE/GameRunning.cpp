#include "precompiled.h"
#include "GameRunning.h"
#include "World.h"
#include "PlayerOutOfBoundsEvent.h"

GameRunning::GameRunning(void){
	_resources.push_back("Field.jpg");
	_resources.push_back("LeftGoalPost.jpg");
	_resources.push_back("RightGoalPost.jpg");
	_resources.push_back("RedPlayer.jpg");
	_resources.push_back("BluePlayer.jpg");
	_resources.push_back("Ball.jpg");
	_resources.push_back("Cursor.png");
	_resources.push_back("VoidTile.jpg");
	_resources.push_back("SolidTile.png");
	_resources.push_back("GravityGuy.jpg");
	_resources.push_back("GravityGuyFlying.jpg");
	_resources.push_back("PlayerRunningSpriteSheet.png");
	_resources.push_back("GravityGuySpriteSheet.png");
	_resources.push_back("CoinSpriteSheet.png");
	_resources.push_back("Background.png");
	_resources.push_back("font1.fnt");
}

void GameRunning::StartGame(){
	_game = new Game(HGE_INSTANCE);
}

void GameRunning::Update(){
	_game->Update();
	//WORLD->Update();
}

void GameRunning::Render(){
	_game->Render();
	//WORLD->Render();
}

void GameRunning::OnNotify(IEvent* event){
	if(PlayerOutOfBoundsEvent *playerOutOfBoundsEvent = dynamic_cast<PlayerOutOfBoundsEvent*>(event)){
		GetToPreviousStateEvent getToPreviousStateEvent;
		BROADCASTER->NotifyAll(&getToPreviousStateEvent);
		return;
	}

	if(KeyEvent* keyEvent = EVENT_IDENTIFIER->IsAKeyEvent(event)){
		HandleKeyboardEvent(keyEvent);
		_game->OnNotify(event);
		return;
	}

	if(MouseEvent* mouseEvent = EVENT_IDENTIFIER->IsAMouseEvent(event)){
		HandleMouseEvent(mouseEvent);		
		_game->OnNotify(event);
		return;
	}

	if(GoalScoredEvent* goalScoredevent = EVENT_IDENTIFIER->IsAGoalScoredEvent(event)){
		_game->OnNotify(event);
	}
}

void GameRunning::HandleKeyboardEvent(KeyEvent* event){
	if(event->GetKeyCode() == VK_ESCAPE && !event->IsKeyPressed()){
		ChangeGameStateTo(IGameState::PAUSE_GAME_STATE);
	}
}

void GameRunning::HandleMouseEvent(MouseEvent* event){

}

void GameRunning::ChangeGameStateTo(IGameState::State new_state){
	GameStateChangeEvent event(new_state);
	BROADCASTER->NotifyAll(&event);
}

void GameRunning::LoadResources(){
	//WORLD->Init();
	_game->Init();
}

std::vector<std::string> GameRunning::GetResourceVector(){
	return _resources;
}

GameRunning::~GameRunning(void){
}
