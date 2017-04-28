#include "precompiled.h"
#include "PlayerManager.h"

PlayerManager::PlayerManager(void){
	m_player_list = new MovableEntityList();
}

void PlayerManager::Update(HGE* hge){
	m_player_list->Update(hge);
}

void PlayerManager::Render(HGE* hge){
	m_player_list->Render(hge);
}

void PlayerManager::OnNotify(IEvent* event){
	m_player_list->OnNotify(event);
}

void PlayerManager::Add(MovableEntity* entity){
	m_player_list->Add(entity);
}

void PlayerManager::Remove(int ID){
	m_player_list->Remove(ID);
}

MovableEntityList* PlayerManager::GetList(){ return m_player_list; }

PlayerManager::~PlayerManager(void){
}
