#include "precompiled.h"
#include "GameStateManager.h"
#include "LoadingState.h"
#include "Options.h"
#include "Broadcaster.h"
#include "KeyEvent.h"
#include "ResourceLoadingCompletedEvent.h"
#include "LoadResourcesEvent.h"
#include "PauseGameState.h"
#include "Menu.h"
#include "GameRunning.h"

GameStateManager* GameStateManager::m_instance = 0;

GameStateManager::GameStateManager(void){
	Register();

	Push(new Menu());
}

void GameStateManager::Update(){
	m_states.top()->Update();
}

void GameStateManager::Render(){
	m_states.top()->Render();
}

void GameStateManager::Push(IGameState* newState){
	m_states.push(newState);
	if(dynamic_cast<LoadingState*>(newState) == NULL){
		LoadResourcesEvent event;
		BROADCASTER->NotifyAll(&event);
	}
}

void GameStateManager::Pop(){
	if(m_states.size() > 1){
		IGameState* e = m_states.top();
		m_states.pop();
		delete e;
	}
}

void GameStateManager::OnNotify(IEvent* event){
	if(GameStateChangeEvent* stateChangeEvent = dynamic_cast<GameStateChangeEvent*>(event)){
		switch(stateChangeEvent->GetState()){
		case IGameState::LOADING_STATE:
			{
				LoadingState *loadingState = new LoadingState(m_states.top()->GetResourceVector());
				Push(loadingState);
				break;
			}
		case IGameState::GAME_RUNNING_STATE:
			{
				GameRunning* gameRunningState = new GameRunning();
				Push(gameRunningState );
				gameRunningState ->StartGame();
				break;
			}
		case IGameState::MENU_STATE:
			Push(new Menu());
			break;
		case IGameState::OPTIONS_STATE:
			Push(new Options());
			break;
		case IGameState::PAUSE_GAME_STATE:
			Push(new PauseGameState());
			break;
		}		
		return;
	}

	if(GetToPreviousStateEvent* getToPreviousStateEvent = dynamic_cast<GetToPreviousStateEvent*>(event)){
		Pop();
		return;
	}

	if(LoadResourcesEvent* loadResourcesEvent = dynamic_cast<LoadResourcesEvent*>(event)){
		Push(new LoadingState(m_states.top()->GetResourceVector()));
		return;
	}

	if(ResourceLoadingCompletedEvent* resourceLoadingCompletedEvent = dynamic_cast<ResourceLoadingCompletedEvent*>(event)){
		Pop();
		m_states.top()->LoadResources();
		return;
	}

	m_states.top()->OnNotify(event);
}

void GameStateManager::Register(){
	BROADCASTER->AddListener(this);
}

GameStateManager* GameStateManager::GetInstance(){
	if(m_instance == NULL) 
		m_instance = new GameStateManager();
	return m_instance;
}

GameStateManager::~GameStateManager(void){
}
