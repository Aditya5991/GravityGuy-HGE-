#include "precompiled.h"
#include "World.h"
#include "Level1.h"
#include "Player.h"
#include "Background.h"
#include "Identifier.h"
#include "Camera.h"
#include "PlayerOutOfBoundsEvent.h"
#include "Broadcaster.h"

World* World::_instance = 0;

World::World(void){
	_rect = new hgeRect(0, 0, GAME_WIDTH, GAME_HEIGHT);
}

void World::Init(){
	CAMERA->Reset();

	_level = new Level1();
	_level->Load();

	_player = new Player(20*32, 12*32);

	_collisionLogic = new CollisionLogic(_level, _player);

	AddObject(new Background());
	AddObject(_player);
}

void World::Update(){
	CAMERA->Update();

	_level->Update();
	for(int i=0; i < _objects.size(); i++){
		_objects[i]->Update();
	}
	_collisionLogic->Update();
}

void World::Render(){
	for(int i=0; i < _objects.size(); i++){
		_objects[i]->Render();
	}
	_level->Render();
	CheckBounds();
}

void World::CheckBounds(){
	if(!_rect->TestPoint(_player->GetX()+_player->GetWidth()/4, _player->GetY()+_player->GetHeight()/4)){
		PlayerOutOfBoundsEvent event;
		BROADCASTER->NotifyAll(&event);
	}
}

void World::AddObject(IObject* object){
	object->SetID(IDENTIFIER->GetID());
	object->Init();
	_objects.push_back(object);
}

void World::RemoveObject(unsigned int ID){
	for(int i=0; i<_objects.size(); i++){
		IObject* object = _objects[i];
		if(object->GetID() == ID)
			_objects.erase(_objects.begin() + i);
	}
}

World* World::GetInstance(){
	if(_instance == NULL)
		_instance = new World();
	return _instance;
}

World::~World(void){
}
