

#pragma once

#include "engine.h"
#include "event.h"

class TimerEvent : public Event
{

public:

    TimerEvent(int timerID)
        : m_TimerID(x) {}
    
    inline int GetID() const { return m_TimerID; }

    EVENT_CLASS_CATEGORY(EventCategoryTimer);
    EVENT_CLASS_TYPE(TimerExpired);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "TimerEvent: m_TimerID: " << m_TimerID;
        return str.str();
    }

private:

    int m_TimerID;

};
