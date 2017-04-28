#include "precompiled.h"
#include "Coin.h"
#include "Camera.h"
#include "time.h"

Coin::Coin(double x, double y) : Entity(x, y){
	_width = _height = 32;
}

void Coin::Init(){
	_rect = new hgeRect(_x, _y, _x + _width, _y + _height);

	_animation = new Animation();
	_animation->SetAnimationSpeed(10);
	_animation->SetNumberOfSprites(7);
	_animation->SetSprites("CoinSpriteSheet.png", 0, 0, 32, 32, (int)_x % 7);
	_animation->SetObject(this);
}

void Coin::Update(){
	_rect->Set(_x, _y, _x + _width, _y + _height);

	_x -= CAMERA->GetXOffset();
	_animation->Update();
}

void Coin::Render(){
	_animation->Render();
}

void Coin::Destroy(){
}

Coin::~Coin(void){
}
