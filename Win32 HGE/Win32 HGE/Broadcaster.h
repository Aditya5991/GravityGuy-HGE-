#pragma once

#include "KeyListener.h"

#ifndef BROADCASTER
#define BROADCASTER Broadcaster::GetInstance()
#endif

class Broadcaster
{
private:
	static Broadcaster* m_instance;
	IListener *m_Listeners;

	Broadcaster(void);

public:

	void AddListener(IListener*);
	void RemoveListener(IListener*);
	void NotifyAll(IEvent*);

	static Broadcaster* GetInstance();

	~Broadcaster(void);
};

