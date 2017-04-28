#include "precompiled.h"
#include "Menu.h"
#include "ResourceManager.h"
#include "LoadResourcesEvent.h"
#include "Broadcaster.h"
#include "GameAppFramework.h"

Menu::Menu(void){
	_resources.push_back("Cursor.png");
	_resources.push_back("MenuPointer.jpg");
	_resources.push_back("font1.fnt");
	_resources.push_back("Menu.png");

	_playButton = new hgeRect(592, 337, 592 + 155, 337 + 44);
	_optionsButton = new hgeRect(544, 412, 544 + 238, 412 + 49);
	_exitButton = new hgeRect(588, 486, 588 + 133, 486 + 52);

	_choice = CHOICE_PLAY;
}

void Menu::Update(){
}

void Menu::Render(){
	float mx, my;
	HGE_INSTANCE->Input_GetMousePos(&mx, &my);
	//font->printf(400, 100, HGETEXT_MIDDLE, "MENU");
	_background->Render();

	_cursor->Render(mx, my);
}

void Menu::OnNotify(IEvent* event){
	KeyEvent* keyEvent = dynamic_cast<KeyEvent*>(event);
	if(keyEvent != NULL){
		HandleKeyboardEvent(keyEvent);
		return;
	}

	MouseEvent* mouseEvent = dynamic_cast<MouseEvent*>(event);
	if(mouseEvent != NULL){
		HandleMouseEvent(mouseEvent);
		return;
	}

}

void Menu::HandleKeyboardEvent(KeyEvent* event){
	if(event->GetKeyCode() == VK_UP && !event->IsKeyPressed()){
		if(_choice > 0){
			_choice--;
		}
		else{
			_choice = MAX_CHOICES - 1;
		}
	}
	if(event->GetKeyCode() == VK_DOWN && !event->IsKeyPressed()){
		if(_choice < MAX_CHOICES-1){
			_choice++;
		}
		else{
			_choice = 0;
		}
	}

	if(event->GetKeyCode() == VK_RETURN && !event->IsKeyPressed()){
		switch(_choice){
		case CHOICE_PLAY:
			ChangeGameStateTo(IGameState::GAME_RUNNING_STATE);
			break;
		case CHOICE_OPTIONS:
			ChangeGameStateTo(IGameState::OPTIONS_STATE);
			break;
		case CHOICE_EXIT:
			exit(1);
			break;
		}
	}
}

void Menu::HandleMouseEvent(MouseEvent* event){
	if(event->GetKeyCode() == VK_LBUTTON){
		if(_playButton->TestPoint(event->GetMouseX(), event->GetMouseY())){
			ChangeGameStateTo(IGameState::GAME_RUNNING_STATE);
			return;
		}
		if (_optionsButton->TestPoint(event->GetMouseX(), event->GetMouseY())){
			ChangeGameStateTo(IGameState::OPTIONS_STATE);
			return;
		}
		if (_exitButton->TestPoint(event->GetMouseX(), event->GetMouseY()))
			exit(1);
	}
}

void Menu::LoadResources(){
	IResource *resource = RESOURCE_MANAGER->GetResource("Cursor.png");
	_cursor = new Sprite((dynamic_cast<Texture*>(resource))->GetData(), 0, 0, 32, 32);

	resource = RESOURCE_MANAGER->GetResource("Menu.png");
	_background = new Entity(0, 0);
	_background->LoadSprite(*(dynamic_cast<Texture*>(resource)), 0, 0, 1280, 720);
}

std::vector<std::string> Menu::GetResourceVector(){
	return _resources;
}

Menu::~Menu(void){
}
