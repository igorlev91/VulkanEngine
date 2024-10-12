

#pragma once

#include <functional>
#include <sstream>
#include <iostream>

#include "engine.h"

class Event;
typedef std::function<void(Event&)> EventCallbackFunction;

enum class EventType
{
    None = 0,
    WindowClose,
    WindowResize,
    KeyPressed,
    KeyReleased,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled,
    ControllerButtonPressed,
    ControllerButtonReleased,
    ControllerAxisMoved,
    JoystickButtonPressed,
    JoystickButtonReleased,
    JoystickAxisMoved,
    JoystickHatMoved,
    JoystickBallMoved,
    TimerExpired,
    ApplicationEvent
};

enum EventCategory
{
    None = 0,
    EventCategoryApplication      = BIT(0),
    EventCategoryInput            = BIT(1),
    EventCategoryKeyboard         = BIT(2),
    EventCategoryMouse            = BIT(3),
    EventCategoryMouseButton      = BIT(4),
    EventCategoryController       = BIT(5),
    EventCategoryControllerButton = BIT(6),
    EventCategoryJoystick         = BIT(7),
    EventCategoryJoystickButton   = BIT(8),
    EventCategoryTimer            = BIT(9)
};

#define EVENT_CLASS_CATEGORY(x) int GetCategoryFlags() const override { return x; }
#define EVENT_CLASS_TYPE(x) static EventType GetStaticType() { return EventType::x; }\
            EventType GetEventType() const override { return GetStaticType(); }\
            const char* GetName() const override { return  #x "Event"; }

class Event
{
    
    friend class EventDispatcher;
    
public:

    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const = 0;
    
    inline bool IsInCategory(EventCategory category)
    {
        return GetCategoryFlags() & category;
    }
    
    inline bool IsHandled() const
    {
        return m_Handled;
    }
    
    inline void MarkAsHandled() 
    {
        m_Handled = true;
    }
    
protected:

    bool m_Handled = false;

};
                
class EventDispatcher
{
    template <typename T>
    using EventFn = std::function<bool(T&)>;
    
public:
    EventDispatcher(Event& event)
        : m_Event(event) {}
    
    template<typename T>
    bool Dispatch(EventFn<T> func)
    {
        if (m_Event.GetEventType() == T::GetStaticType())
        {
            m_Event.m_Handled |= func(*(T*)&m_Event);
            return true;
        }
        return false;
    }
    
private:

    Event& m_Event;
    
};

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
    return os << e.ToString();
}
