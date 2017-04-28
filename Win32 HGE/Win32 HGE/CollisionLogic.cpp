#include "precompiled.h"
#include "CollisionLogic.h"
#include "Camera.h"

CollisionLogic::CollisionLogic(ILevel* level, Player* player){
	_level = level;
	_player = player;
}

void CollisionLogic::Update(){
	UpdateLevelCollision();
}

void CollisionLogic::UpdateLevelCollision(){
	double x = _player->GetX() + CAMERA->GetX();
	double y = _player->GetY() + CAMERA->GetY();

	bool _collidingAlongY = false;
	bool _collidingAlongX = false;

	if((_level->GetTile(x/32 + 1, y/32)->IsSolid()) || (_level->GetTile(x/32 + 1.5, y/32)->IsSolid()) || (_level->GetTile(x/32 + 0.5, y/32)->IsSolid())){
		_collidingAlongY = true;
	}else if((_level->GetTile(x/32 + 1, y/32 + 2)->IsSolid()) || (_level->GetTile(x/32 + 1.5, y/32 + 2)->IsSolid()) || (_level->GetTile(x/32 + 0.5, y/32 + 2)->IsSolid())){
		_collidingAlongY = true;
	}

	if(_level->GetTile(x/32 + 2, y/32 + 1)->IsSolid() || (_level->GetTile(x/32 + 2, y/32 + 0.1)->IsSolid()) || (_level->GetTile(x/32 + 2, y/32 + 1.9)->IsSolid())){
		_collidingAlongX = true;
	}

	if(_collidingAlongX){
		_player->Move(-CAMERA->GetXOffset(), 0);
	}
	if(!_collidingAlongY){
		_player->Move(0, _player->GetVelY());
		_player->SetMovementState(Player::MOVEMENT_FALLING);
	}else{
		_player->SetMovementState(Player::MOVEMENT_RUNNING);
	}
}

CollisionLogic::~CollisionLogic(void){

}
