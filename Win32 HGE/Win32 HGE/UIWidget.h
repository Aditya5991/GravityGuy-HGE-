#pragma once

#include "IObject.h"
#include "IEvent.h"

class UIWidget : public IObject {

protected:
	double _x, _y;
	std::string _text;
	FontResource *_font;

public:

	UIWidget(double x, double y){
		_x = x;
		_y = y;
	}

	virtual void Init() override = 0;
	virtual void Update() override = 0;
	virtual void Render() override = 0;
	virtual void Destroy() override = 0;

	double GetX(){ return _x; }
	double GetY(){ return _y; }
	std::string GetText(){ return _text; }
	void SetFont(IResource* font){ _font = dynamic_cast<FontResource*>(font); }
};
