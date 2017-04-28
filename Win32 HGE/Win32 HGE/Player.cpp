#include "precompiled.h"
#include "Player.h"
#include "Broadcaster.h"
#include "World.h"
#include "Utils.h"
#include "Camera.h"
#include "hgefont.h"
#include "GameAppFramework.h"

Player::Player(double x, double y) : MovableEntity(x, y){
	Register();

	_direction = 3;
	_sprite = new Sprite(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("GravityGuy.jpg"))->GetData(), 0, 0, 64, 64);
	_flyingSprite = new Sprite(dynamic_cast<Texture*>(RESOURCE_MANAGER->GetResource("GravityGuyFlying.jpg"))->GetData(), 0, 0, 64, 64);
	_width = _height = 64;
	_rect = new hgeRect(_x, _y, _x + _width, _y + _height);
}

void Player::Init(){
	_velY = 3;

	/* Init Animations */
	// Running Animation
	Animation* runningAnimation = new Animation();
	runningAnimation->SetAnimationSpeed(4);
	runningAnimation->SetNumberOfSprites(9);
	runningAnimation->SetSprites("GravityGuySpriteSheet.png", 0 * 64, 0 * 64, 64, 64, 0);
	runningAnimation->SetObject(this);

	//Falling Animation
	Animation* fallingAnimation = new Animation();
	fallingAnimation->SetAnimationSpeed(10);
	fallingAnimation->SetNumberOfSprites(9);
	fallingAnimation->SetSprites("GravityGuySpriteSheet.png", 0 * 64, 1 * 64, 64, 64, 0);
	fallingAnimation->SetObject(this);

	_animations.push_back(runningAnimation);
	_animations.push_back(fallingAnimation);
}

void Player::Update(){
	_rect->Set(_x, _y, _x + _width, _y + _height);
	switch(_movementState){
	case MOVEMENT_RUNNING:
		_animations[ANIMATION_RUNNING_INDEX]->Update();
		break;
	case MOVEMENT_FALLING:
		_animations[ANIMATION_FALLING_INDEX]->Update();
		break;
	}
}

void Player::Render(){
	switch(_movementState){
	case MOVEMENT_RUNNING:
		_animations[ANIMATION_RUNNING_INDEX]->Render();
		//_sprite->Render(_x, _y);
		break;
	case MOVEMENT_FALLING:
		_animations[ANIMATION_FALLING_INDEX]->Render();
		//_flyingSprite->Render(_x, _y);
		break;
	}

}

void Player::Move(double velX, double velY){
	_x += velX;
	_y += velY;
}
void Player::OnNotify(IEvent* event){
	if(KeyEvent *keyEvent = dynamic_cast<KeyEvent*>(event)){
		HandleKeyboardEvent(keyEvent);
	}
}

void Player::HandleKeyboardEvent(KeyEvent* event){
	if(event->GetKeyCode() == VK_SPACE && event->IsKeyPressed() && _movementState == MOVEMENT_RUNNING){
		_velY *= -1;
		_y = (_velY < 0) ? (_y - 5) : (_y + 5);
		_animations[ANIMATION_RUNNING_INDEX]->Flip();
		_animations[ANIMATION_FALLING_INDEX]->Flip();
	}
}

void Player::Register(){
	BROADCASTER->AddListener(this);
}

void Player::SetMovementState(MovementState state){ _movementState = state; }

void Player::Destroy(){

}

Player::~Player(){

}
