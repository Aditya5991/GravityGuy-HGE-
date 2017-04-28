#include "precompiled.h"
#include "Entity.h"

Entity::Entity(double x, double y){
	_x = x;
	_y = y;
}

void Entity::Init(){

}

void Entity::LoadSprite(Texture texture, int startX, int startY, int width, int height){
	_sprite = new Sprite(texture.GetData(), startX, startY, width, height);
	_width = _sprite->GetWidth();
	_height = _sprite->GetHeight();
	_sprite->Update(_x, _y);
}
void Entity::Update(){
	_sprite->Update(_x, _y);
}

void Entity::Render(){
	_sprite->Render(_x, _y);
}

double Entity::GetX(){ return _x; }
double Entity::GetY(){ return _y; }
int Entity::GetWidth(){ return _width; }
int Entity::GetHeight(){ return _height; }
hgeRect* Entity::GetRectangle(){ return _sprite->GetRectangle(); }
bool Entity::TestPoint(float x, float y){ return _sprite->GetRectangle()->TestPoint(x, y); }

void Entity::SetXY(double x, double y){_x = x; _y = y;}

void Entity::SetFont(hgeFont* font){ _font = font; }

void Entity::Destroy(){

}

Entity::~Entity(void){
}
