#pragma once

#include "Utils.h"

class Timer
{
private:
	int updates;
	double m_deltaTime;
	double m_startTime;
	double m_currentTime;
	double m_currentTimeInSeconds;
	bool m_isRunning;

public:
	Timer(void);

	void Start();
	void Stop();
	void Update();
	void Render();
	bool IsRunning();
	double CurrentTime();
	double CurrentTimeInSeconds();

	~Timer(void);

};
