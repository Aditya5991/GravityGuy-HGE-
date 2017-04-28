#include "precompiled.h"
#include "Identifier.h"

Identifier* Identifier::_instance = 0;

Identifier::Identifier(){
	_ID = 0;
}

unsigned int Identifier::GetID(){
	return _ID++;
}

Identifier* Identifier::GetInstance(){
	if(_instance == NULL)
		_instance = new Identifier();
	return _instance;
}
