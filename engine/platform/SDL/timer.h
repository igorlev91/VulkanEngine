

#pragma once

#include <functional>
#include "engine.h"

typedef uint (*TimerCallbackFunction) (uint, void*);

class Timer
{
    
public:

    Timer(uint interval);
    Timer(uint interval, TimerCallbackFunction& callback);
    ~Timer();
    
    void Start();
    void Stop();
    int GetID() const { return m_TimerID; }
    void SetTimerInterval(uint interval) { m_Interval = interval; }
    void SetEventCallback(const TimerCallbackFunction& callback);
    
private:

    uint m_Interval;
    int m_TimerID;
    TimerCallbackFunction m_TimerCallback;

};
