#include "precompiled.h"
#include "UIButton.h"
#include "GameAppFramework.h"

UIButton::UIButton(double x, double y, std::string text) : UIWidget(x, y)
{
	_text = text;
}

void UIButton::Init(){
	_xPadding = 10;
	_yPadding = 10;

	_width = _font->GetStringWidth(_text) + 2 * _xPadding;
	_height = _font->GetHeight() + 2 * _yPadding;
	
	_rectangle = new hgeRect(_x, _y, _x + _width, _y + _height);

	_xTop = _x - _xPadding;
	_yTop = _y - _yPadding;
}

void UIButton::Update(){

}

void UIButton::Render(){
	_font->Render(_x, _y, _text);
	HGE_INSTANCE->Gfx_RenderLine(_xTop, _yTop, _xTop + _width, _yTop);
	HGE_INSTANCE->Gfx_RenderLine(_xTop + _width, _yTop, _xTop + _width, _yTop + _height);
	HGE_INSTANCE->Gfx_RenderLine(_xTop + _width, _yTop + _height, _xTop, _yTop + _height);
	HGE_INSTANCE->Gfx_RenderLine(_xTop, _yTop + _height, _xTop, _yTop);
}

void UIButton::Destroy(){

}

bool UIButton::IsClicked(MouseEvent* event){
	return _rectangle->TestPoint(event->GetMouseX(), event->GetMouseY());
}

UIButton::~UIButton(){

}
