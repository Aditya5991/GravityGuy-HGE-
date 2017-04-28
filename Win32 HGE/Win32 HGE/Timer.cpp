#include "precompiled.h"
#include "Timer.h"

Timer::Timer(void){
	m_isRunning = false;
	m_deltaTime = 1 / FPS;
}

void Timer::Start(){
	m_isRunning = true;
	m_deltaTime = 0.01;
	m_startTime = 0;
	m_currentTime = 0;
}

void Timer::Update(){
	m_currentTime += m_deltaTime;
	m_currentTimeInSeconds = (int)m_currentTime % FPS;
}

void Timer::Stop(){
	m_isRunning = false;
	m_startTime = 0;
	m_currentTime = 0;
}

double Timer::CurrentTimeInSeconds(){ return m_currentTimeInSeconds; }

double Timer::CurrentTime(){ return m_currentTime; }

bool Timer::IsRunning(){ return m_isRunning; }

Timer::~Timer(void){

}