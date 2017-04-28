#include "precompiled.h"
#include "Loader.h"

Loader::Loader(HGE* hge){
	this->hge = hge;
}

hgeSprite* Loader::loadSprite(char* texture_path, int x, int y, int width, int height){
	return new hgeSprite(hge->Texture_Load(texture_path), x, y, width, height);
}

Loader::~Loader(void){
}
