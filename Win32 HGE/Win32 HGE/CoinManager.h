#pragma once

#ifndef COIN_MANAGER
#define COIN_MANAGER CoinManager::GetInstance()
#endif

class CoinManager
{
private:
	static CoinManager* _instance;
	CoinManager(void);

public:
	void AddCoin(double, double);

	static CoinManager* GetInstance();
	
};
