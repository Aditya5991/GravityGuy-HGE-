#include "precompiled.h"
#include "SolidTile.h"
#include "GameAppFramework.h"
#include "Utils.h"

SolidTile::SolidTile(){
	//_sprite = new Sprite(HGE_INSTANCE->Texture_Load("SolidTile.jpg"), 0, 0, 32, 32);
	_sprite = new Sprite(RESOURCE_MANAGER->GetResource("SolidTile.png"), 0, 0, 32, 32);
}
 
void SolidTile::Update(){

}

void SolidTile::Render(double x, double y){
	_sprite->Render(x * TILE_SIZE, y * TILE_SIZE);
}

bool SolidTile::IsSolid(){
	return true;
}

SolidTile::~SolidTile(void){
}

