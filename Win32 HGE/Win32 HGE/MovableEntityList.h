#pragma once

#include "KeyEvent.h"
#include "MovableEntity.h"

class MovableEntityList
{
private:
	int m_ID;

public:
	/*struct Entry{
		MovableEntity* entity;
		int ID;
		Entry *next, *prev;

		Entry(MovableEntity* entity, int ID){
			this->entity = entity;
			this->ID = ID;
			this->next = this->prev = NULL;
		}

		MovableEntity* getEntity();
		int getID();
	};*/
	MovableEntity *_start, *_end;

public:
	MovableEntityList(void);

	void Update(HGE*);
	void Render(HGE*);

	void OnNotify(IEvent*);

	void Add(MovableEntity*);
	void Remove(int);
	MovableEntity* GetStart();

	~MovableEntityList(void);
};

