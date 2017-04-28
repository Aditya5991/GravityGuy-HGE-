#include "precompiled.h"
#include "CoinManager.h"
#include "Coin.h"
#include "World.h"

CoinManager* CoinManager::_instance = 0;

CoinManager::CoinManager(void){
}

void CoinManager::AddCoin(double x, double y){
	WORLD->AddObject(new Coin(x, y));
}

CoinManager* CoinManager::GetInstance(){
	if(_instance == NULL)
		_instance = new CoinManager();
	return _instance;
}
