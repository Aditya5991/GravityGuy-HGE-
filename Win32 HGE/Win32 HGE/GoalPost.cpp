#include "precompiled.h"
#include "GoalPost.h"

GoalPost::GoalPost(double x, double y) : Entity(x, y){
	rect = new hgeRect();
}

void GoalPost::render(HGE* hge){
	_sprite->Render(_x, _y);
}

GoalPost::~GoalPost(void){
}
