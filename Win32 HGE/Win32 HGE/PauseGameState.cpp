#include "precompiled.h"
#include "PauseGameState.h"
#include "ResourceManager.h"
#include "GameAppFramework.h"
#include "GetToPreviousStateEvent.h"
#include "Utils.h"

PauseGameState::PauseGameState(){
	_resources.push_back("ResumeButton.png");
	_resources.push_back("OptionsButton.png");
	_resources.push_back("ExitButton.png");
	_resources.push_back("Cursor.png");
	_resources.push_back("font1.fnt");

	m_choice = CHOICE_RESUME;
}

void PauseGameState::Update(){

}

void PauseGameState::Render(){
	float mx, my;
	HGE_INSTANCE->Input_GetMousePos(&mx, &my);
	//font->printf(400, 100, HGETEXT_MIDDLE, "MENU");
	m_resumeButton->Render();
	m_optionsButton->Render();
	m_exitButton->Render();

	m_cursor->Render(mx, my);
	m_pointer->Render(350, 100 + 100*m_choice);

	m_font->Render(GAME_WIDTH/2 - 100, 25, "ESCAPE to Unpause");
}

void PauseGameState::HandleKeyboardEvent(KeyEvent* event){
	if(event->GetKeyCode() == VK_ESCAPE && !event->IsKeyPressed()){
		GetToPreviousStateEvent event;
		BROADCASTER->NotifyAll(&event);
		return;
	}
	if(event->GetKeyCode() == VK_UP && !event->IsKeyPressed()){
		if(m_choice > 0)
			m_choice--;
		else
			m_choice = MAX_CHOICES - 1;
		return;
	}
	if(event->GetKeyCode() == VK_DOWN && !event->IsKeyPressed()){
		if(m_choice < MAX_CHOICES-1)
			m_choice++;
		else
			m_choice = 0;
		return;
	}

	if(event->GetKeyCode() == VK_RETURN && !event->IsKeyPressed()){
		switch(m_choice){
		case CHOICE_RESUME:
		{
			GetToPreviousStateEvent event;
			BROADCASTER->NotifyAll(&event);
			break;
		}
		case CHOICE_OPTIONS:
			ChangeGameStateTo(IGameState::OPTIONS_STATE);
			break;
		case CHOICE_EXIT:
			exit(1);
			break;
		}
	}
}

void PauseGameState::HandleMouseEvent(MouseEvent* event){
	if(event->GetKeyCode() == VK_LBUTTON){
		if(m_resumeButton->TestPoint(event->GetMouseX(), event->GetMouseY())){
			GetToPreviousStateEvent event;
			BROADCASTER->NotifyAll(&event);
			return;
		}
		if(m_optionsButton->TestPoint(event->GetMouseX(), event->GetMouseY())){
			ChangeGameStateTo(IGameState::OPTIONS_STATE);
			return;
		}
		if(m_exitButton->TestPoint(event->GetMouseX(), event->GetMouseY()))
			exit(1);
	}
}

void PauseGameState::LoadResources(){
	IResource *resource = RESOURCE_MANAGER->GetResource("ResumeButton.png");
	int factor = 0;
	m_resumeButton = new Entity(400, 100 + 100*factor++);
	m_resumeButton->LoadSprite(*(dynamic_cast<Texture*>(resource)), 0, 0, 64, 32);

	resource = RESOURCE_MANAGER->GetResource("OptionsButton.png");
	m_optionsButton = new Entity(400, 100 + 100*factor++);
	m_optionsButton->LoadSprite(*(dynamic_cast<Texture*>(resource)), 0, 0, 64, 32);

	resource = RESOURCE_MANAGER->GetResource("ExitButton.png");
	m_exitButton = new Entity(400, 100 + 100*factor);
	m_exitButton->LoadSprite(*(dynamic_cast<Texture*>(resource)), 0, 0, 64, 32);

	resource = RESOURCE_MANAGER->GetResource("Cursor.png");
	m_cursor = new Sprite((dynamic_cast<Texture*>(resource))->GetData(), 0, 0, 32, 32);

	resource = RESOURCE_MANAGER->GetResource("MenuPointer.jpg");
	m_pointer = new Sprite((dynamic_cast<Texture*>(resource))->GetData(), 0, 0, 32, 32);

	resource = RESOURCE_MANAGER->GetResource("font1.fnt");
	m_font = dynamic_cast<FontResource*>(resource);
}

void PauseGameState::OnNotify(IEvent* event){
	KeyEvent* keyEvent = dynamic_cast<KeyEvent*>(event);
	if(keyEvent != NULL){
		HandleKeyboardEvent(keyEvent);
	}
	
	MouseEvent* mouseEvent = dynamic_cast<MouseEvent*>(event);
	if(mouseEvent != NULL){
		HandleMouseEvent(mouseEvent);
	}
}

PauseGameState::~PauseGameState(){
}
