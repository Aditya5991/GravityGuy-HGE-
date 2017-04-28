#include "precompiled.h"
#include "GameAppFramework.h"
#include "Animation.h"
#include "Texture.h"
#include "ResourceManager.h"

Animation::Animation(){
	_updates = 0;
	_currentSpriteIndex = 0;
}

void Animation::Update(){
	_updates++;
	if(_updates % _animationSpeed == 0){
		_currentSpriteIndex++;
		_updates = 0;
	}

	_spriteToRender = _sprites[_currentSpriteIndex % _numberOfSprites];
}

void Animation::Render(){
	_spriteToRender->Render(_entity->GetX(), _entity->GetY());
}

void Animation::SetNumberOfSprites(int numberOfSprites){
	_numberOfSprites = numberOfSprites;
}

void Animation::SetAnimationSpeed(int animationSpeed){
	_animationSpeed = animationSpeed;
}

void Animation::SetSprites(std::string path,int startX, int startY, int widthOfSingleSprite, int heightOfSingleSprite, int startingIndexOfSprite){
	for(int i=0; i<_numberOfSprites; i++){
		Sprite* sprite = new Sprite(RESOURCE_MANAGER->GetResource(path), (startX + widthOfSingleSprite)*i, startY, widthOfSingleSprite, heightOfSingleSprite);
		_sprites.push_back(sprite);
	}

	_currentSpriteIndex = startingIndexOfSprite;
	_spriteToRender = _sprites[_currentSpriteIndex];
}

void Animation::SetObject(Entity* entity){
	_entity = entity;
}

void Animation::Flip(){
	for(int i=0; i<_numberOfSprites; i++){
		Sprite* sprite = _sprites[i];
		sprite->Flip();
	}
}

Animation::~Animation(void){
}
