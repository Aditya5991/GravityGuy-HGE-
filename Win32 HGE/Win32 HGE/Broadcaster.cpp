#include "precompiled.h"
#include "Broadcaster.h"

Broadcaster* Broadcaster::m_instance = 0;

Broadcaster::Broadcaster(void){
	m_Listeners = NULL;
}

void Broadcaster::AddListener(IListener* listener){
	listener->next = m_Listeners;
	m_Listeners = listener;
}

void Broadcaster::RemoveListener(IListener* listener){
	IListener* ptr_listener = m_Listeners;
	while(ptr_listener != NULL){
		if(ptr_listener->next == listener){
			ptr_listener->next = ptr_listener->next->next;
			delete listener;
			break;
		}
		ptr_listener = ptr_listener->next;
	}
}

void Broadcaster::NotifyAll(IEvent* event){
	IListener* ptr_listener = m_Listeners;
	while(ptr_listener != NULL){
		ptr_listener->OnNotify(event);
		ptr_listener = ptr_listener->next;
	}
}

Broadcaster* Broadcaster::GetInstance(){
	if(m_instance == NULL)
		m_instance = new Broadcaster();
	return m_instance;
}

Broadcaster::~Broadcaster(void){
}
