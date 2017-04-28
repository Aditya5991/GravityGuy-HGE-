#include "precompiled.h"
#include "EntityList.h"

EntityList::EntityList(void){
	m_ID = 0;
	m_start = m_end = NULL;
}

EntityList::Entry* EntityList::NewEntry(Entity* entity){
	return new Entry(entity, m_ID++);
}

void EntityList::Update(HGE* hge){
	Entry* entry = m_start;
	while(entry != NULL){
		entry->GetEntity()->Update();
		entry = entry->m_next;
	}
}

void EntityList::Render(HGE* hge){
	Entry* entry = m_start;
	while(entry != NULL){
		entry->GetEntity()->Render();
		entry = entry->m_next;
	}
}

void EntityList::Add(Entity* entity){
	if(m_start == NULL){
		m_start = m_end = NewEntry(entity);
		return;
	}

	Entry *new_entry = NewEntry(entity);
	m_end->m_next = new_entry;
	new_entry->m_prev = m_end;
	m_end = new_entry;
}

void EntityList::Remove(int ID){
}

void EntityList::RemoveFirst(){
	if(m_start == NULL){
		delete m_start;
		m_start = m_end = NULL;
		return;
	}

	Entry* delete_entry = m_start;
	m_start = m_start->m_next;
	delete delete_entry;
}

EntityList::Entry* EntityList::GetStart(){ return m_start; }

Entity* EntityList::Entry::GetEntity(){
	return m_entity;
}

int EntityList::Entry::GetID(){
	return m_ID;
}


EntityList::~EntityList(void){
}
