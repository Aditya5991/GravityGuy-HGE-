#include "precompiled.h"
#include "Sprite.h"
#include "Camera.h"
#include "Texture.h"

Sprite::Sprite(HTEXTURE texture, int startX, int startY, int width, int height){
	_width = width;
	_height = height;
	_sprite = new hgeSprite(texture, startX, startY, width, height);
	_rectangle = new hgeRect();
}

Sprite::Sprite(IResource* resource, int startX, int startY, int width, int height){
	Texture* texture = dynamic_cast<Texture*>(resource);
	_sprite = new hgeSprite(texture->GetData(), startX, startY, width, height);
	_rectangle = new hgeRect();
}

Sprite::Sprite(int color, int width, int height){
	_sprite->SetColor(color);
}

void Sprite::Update(double x, double y){
	_rectangle->Set(x, y, x + _width, y + _height);
}

void Sprite::Render(double x, double y){
	_sprite->Render(x, y);
}

void Sprite::RenderEx(double x, double y, double rot, double xScale, double yScale){
	_sprite->RenderEx(x, y, rot, xScale, yScale);
}

void Sprite::RenderStretch(double x1, double y1, double x2, double y2){
	_sprite->RenderStretch(x1, y1, x2, y2);
}

void Sprite::Flip(){
	bool flipX, flipY;
	_sprite->GetFlip(&flipX, &flipY);
	_sprite->SetFlip(flipX, (flipY) ? false : true);
}

void Sprite::Set(double x, double y){
	_x = x;
	_y = y;
}

int Sprite::GetWidth(){ return _sprite->GetWidth(); }
int Sprite::GetHeight(){ return _sprite->GetHeight(); }

hgeRect* Sprite::GetRectangle(){
	return _rectangle;
}

Sprite::~Sprite(void){
}
