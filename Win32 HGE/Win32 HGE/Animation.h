#pragma once

#include "Sprite.h"
#include "Entity.h"
#include <vector>
#include <string>

class Animation
{
private:
	int _numberOfSprites;
	int _currentSpriteIndex;
	int _updates;
	int _animationSpeed;

	bool xflipped, yFlipped;

	std::vector<Sprite*> _sprites;
	Sprite* _spriteToRender;
	Entity* _entity;

public:
	Animation(void);

	void Update();
	void Render();

	void Flip();

	void SetNumberOfSprites(int);
	void SetAnimationSpeed(int);
	void SetSprites(std::string,int, int, int, int, int);
	void SetObject(Entity*);

	~Animation(void);
};

