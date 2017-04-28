#include "precompiled.h"
#include "MovableEntity.h"

MovableEntity::MovableEntity(double x, double y) : Entity(x, y){
	_initX = x;
	_initY = y;
	_velX = _velY = 0;
	_force = new Force();
	_prev = _next = NULL;
}

void MovableEntity::Init(){

}

void MovableEntity::UpdateGoalScoredAnimation(){
	_velX = (_initX - _x) / 50;
	_velY = (_initY - _y) / 50;

	_x += _velX;
	_y += _velY;
}

void MovableEntity::Update(){}
void MovableEntity::Render(){}

void MovableEntity::Reset(){
	_x = _initX;
	_y = _initY;
	_velX = _velY = _initY;
}

void MovableEntity::Move(double dx, double dy){
	_x += dx;
	_y += dy;
	_rect->Set(_x, _y, _x + _width, _y + _height);
}

void MovableEntity::LoadSprite(Texture texture, int startX, int startY, int width, int height){
	_sprite = new Sprite(texture.GetData(), startX, startY, width, height);
	_width = _sprite->GetWidth();
	_height = _sprite->GetHeight();
}

void MovableEntity::OnNotify(IEvent* event){
}

double MovableEntity::GetVelX(){ return _velX; }
double MovableEntity::GetVelY(){ return _velY; }
double MovableEntity::GetVelocity(){ return sqrt(_velX*_velX + _velY*_velY); }
Force* MovableEntity::GetForce(){ return _force; }
void MovableEntity::SetVelX(double velX){ _velX = velX; }
void MovableEntity::SetVelY(double velY){ _velY = velY; }
void MovableEntity::SetForce(double magnitude, double angle){ _force->setMagnitude(magnitude); _force->setAngle(angle); }

void MovableEntity::Destroy(){

}

MovableEntity::~MovableEntity(void)
{
}
