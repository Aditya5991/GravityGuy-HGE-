#pragma once

#include "UIWidget.h"
#include "MouseEvent.h"

class UIButton : public UIWidget {
private:
	double _width, _height;
	hgeRect* _rectangle;
	double _xPadding, _yPadding;
	double _xTop, _yTop;

public:
	UIButton(double, double, std::string);

	void Init() override;
	void Update() override;
	void Render() override;
	void Destroy() override;

	bool IsClicked(MouseEvent*);

	~UIButton(void);

};