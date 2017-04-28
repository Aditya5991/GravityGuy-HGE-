#pragma once

#include "IResource.h"
#include "hgeFont.h"

class FontResource : public IResource
{
private:
	hgeFont *m_font;

public:
	FontResource(std::string);

	void Load() override;
	void Render(int, int, std::string);
	bool IsLoaded() override;

	double GetStringWidth(std::string);
	double GetHeight();

	~FontResource();
};
