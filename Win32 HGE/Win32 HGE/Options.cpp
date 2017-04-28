#include "precompiled.h"
#include "Options.h"
#include "GameStateChangeEvent.h"

Options::Options(void){
	_resources.push_back("font1.fnt");
}

void Options::Update(){
	//font = new hgeFont("font1.fnt");
}

void Options::Render(){
	//font->printf(400, 100, HGETEXT_MIDDLE, "Options");
}

void Options::HandleKeyboardEvent(KeyEvent* event){
	if(event->GetKeyCode() == VK_ESCAPE && !event->IsKeyPressed()){
		GetToPreviousStateEvent getToPreviousStateEvent;
		BROADCASTER->NotifyAll(&getToPreviousStateEvent);
		//ChangeGameStateTo(new Menu());
	}
}

void Options::HandleMouseEvent(MouseEvent* event){
}

void Options::OnNotify(IEvent* event){
	KeyEvent* keyEvent = dynamic_cast<KeyEvent*>(event);
	if(keyEvent != NULL){
		HandleKeyboardEvent(keyEvent);
	}
}

void Options::LoadResources(){
}

std::vector<std::string> Options::GetResourceVector(){
	return _resources;
}

void Options::ChangeGameStateTo(IGameState::State new_state){
	GameStateChangeEvent stateChangeEvent(new_state);
	BROADCASTER->NotifyAll(&stateChangeEvent);
}

Options::~Options(void){

}
