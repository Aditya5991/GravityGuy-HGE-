#pragma once

#include "ILevel.h"
#include "IObject.h"
#include "CollisionLogic.h"
#include <vector>

#ifndef WORLD
#define WORLD World::GetInstance()
#endif

class World
{
private:
	CollisionLogic *_collisionLogic;
	ILevel *_level;
	Player *_player;
	hgeRect* _rect;
	std::vector<IObject*> _objects;
	static World* _instance;

	World(void);

public:
	void Init();
	void Update();
	void Render();

	void CheckBounds();
	void AddObject(IObject*);
	void RemoveObject(unsigned int);

	static World* GetInstance();

	~World(void);
};
