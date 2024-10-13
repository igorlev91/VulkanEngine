

#include <SDL.h>

#include "timer.h"

Timer::Timer(uint interval)
    : m_Interval(interval), m_TimerID(0), m_TimerCallback(nullptr)
{
}

Timer::Timer(uint interval, TimerCallbackFunction& callback)
    : m_Interval(interval), m_TimerID(0), m_TimerCallback(callback)
{
}

Timer::~Timer()
{
    Stop();
}

void Timer::Start()
{
    m_TimerID = SDL_AddTimer(m_Interval, (SDL_TimerCallback) m_TimerCallback, (void*)(&m_TimerID));
}

void Timer::Stop()
{
    SDL_RemoveTimer(m_TimerID);
}

void Timer::SetEventCallback(const TimerCallbackFunction& callback)
{
    m_TimerCallback = callback;
}

