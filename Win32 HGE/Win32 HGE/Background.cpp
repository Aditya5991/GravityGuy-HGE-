#include "precompiled.h"
#include "Background.h"

Background::Background(void) : Entity(0, 0){
	_sprite = new Sprite(RESOURCE_MANAGER->GetResource("Background.png"), 0, 0, 1280*10, 720);
}

void Background::Update(){
	_x -= 0.5;
}

void Background::Render(){
	_sprite->Render(_x, _y);
}

Background::~Background(){
}
