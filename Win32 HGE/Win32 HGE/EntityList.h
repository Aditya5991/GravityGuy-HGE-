#pragma once

#include "Entity.h"

class EntityList
{
private:
	int m_ID;
	
public:
	struct Entry{
		Entity* m_entity;
		int m_ID;
		Entry *m_next, *m_prev;

		Entry(Entity* entity, int ID){
			m_entity = entity;
			m_ID = ID;
			m_next = m_prev = NULL;
		}

		Entity* GetEntity();
		int GetID();
	};
	Entry *m_start, *m_end;

public:
	EntityList(void);

	Entry* NewEntry(Entity*);
	void Update(HGE*);
	void Render(HGE*);
	void Add(Entity*);
	void Remove(int);
	void RemoveFirst();
	Entry* GetStart();

	~EntityList(void);
};

