#include "precompiled.h"
#include "Ball.h"

Ball::Ball(double x, double y) : MovableEntity(x, y){
}

void Ball::Init(){

}

bool IsBetween(double value, double lower, double upper){
	return ((value>=lower) && (value <= upper));
}

void Ball::CheckBounds(){
	if(_x < constants::FieldXmin){
		if(IsBetween(_y, constants::leftGoalPostTop, constants::leftGoalPostBottom)){
		}
		_velX *= -1;
		//force->setAngle(Utils::PI - force->getAngle());
		_x = (double)constants::FieldXmin;
	}
	if((_x + _width) > constants::FieldXmax){
		if(IsBetween(_y, constants::rightGoalPostTop, constants::rightGoalPostBottom)){
			return;
		}
		_velX *= -1;
		//force->setAngle(Utils::PI - force->getAngle());
		_x =  constants::FieldXmax - _width;
	}

	if(_y < constants::FieldYmin){
		_velY *= -1;
		//m_force->setAngle(-m_force->getAngle());
		_y = (double)constants::FieldYmin;
	}
	if((_y + _height) > constants::FieldYmax){
		_velY *= -1;
		//m_force->setAngle(-m_force->getAngle());
		_y = constants::FieldYmax - _height;
	}
}

void Ball::OnNotify(IEvent* event){
	if(GoalScoredEvent *goalScoredEvent = dynamic_cast<GoalScoredEvent*>(event)){
		Reset();
	}
}

void Ball::Update(){
	CheckBounds();

	_velX *= 0.97;
	_velY *= 0.97;

	_x += _velX;
	_y += _velY;
}

void Ball::Render(){
	_sprite->Render(_x, _y);
}

void Ball::Destroy(){

}

Ball::~Ball(void){
}
