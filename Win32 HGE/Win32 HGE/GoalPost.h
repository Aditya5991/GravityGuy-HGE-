#pragma once

#include "Entity.h"
#include "hgeRect.h"

class GoalPost : public Entity
{
private:
	hgeRect* rect;
public:
	GoalPost(double, double);

	void render(HGE*);

	~GoalPost(void);
};

