#pragma once

#include "KeyEvent.h"
#include "MovableEntityList.h"

class PlayerManager
{
private:
	MovableEntityList *m_player_list;

public:
	PlayerManager(void);
	
	void Update(HGE*);
	void Render(HGE*);

	void OnNotify(IEvent*);

	void Add(MovableEntity*);
	void Remove(int);
	MovableEntityList* GetList();
	
	~PlayerManager(void);
};

