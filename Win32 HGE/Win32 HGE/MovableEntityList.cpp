#include "precompiled.h"
#include "MovableEntityList.h"

MovableEntityList::MovableEntityList(void){
	m_ID = 0;
	_start = _end = NULL;
}


void MovableEntityList::Update(HGE* hge){
	MovableEntity* entity = _start;
	while(entity != NULL){
		entity->Update();
		entity = entity->_next;
	}
}

void MovableEntityList::Render(HGE* hge){
	MovableEntity* entity = _start;
	while(entity != NULL){
		entity->Render();
		entity = entity->_next;
	}
}

void MovableEntityList::OnNotify(IEvent* event){
	MovableEntity* entity = _start;
	while(entity != NULL){
		entity->OnNotify(event);
		entity = entity->_next;
	}
}

void MovableEntityList::Add(MovableEntity* entity){
	if(_start == NULL){
		_start = _end = entity;
		return;
	}

	MovableEntity *new_entry = entity;
	_end->_next = new_entry;
	new_entry->_prev = _end;
	_end = new_entry;
}

void MovableEntityList::Remove(int ID){
}

MovableEntity* MovableEntityList::GetStart(){ return _start; }

MovableEntityList::~MovableEntityList(void){
}
