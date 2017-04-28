#pragma once

#include "IResource.h"

class Texture : public IResource
{
private:
	HTEXTURE texture;

public:
	Texture(std::string);
	void Load() override;
	bool IsLoaded() override;
	HTEXTURE GetData();

	~Texture(void);
};
