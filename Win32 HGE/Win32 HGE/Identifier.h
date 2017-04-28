#pragma once

#ifndef IDENTIFIER
#define IDENTIFIER Identifier::GetInstance()
#endif

class Identifier
{
private:
	unsigned int _ID;
	static Identifier* _instance;

	Identifier(void);

public:
	unsigned int GetID();

	static Identifier* GetInstance();
};
