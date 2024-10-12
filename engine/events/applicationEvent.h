

#pragma once

#include "engine.h"
#include "event.h"

class WindowCloseEvent : public Event
{

public:

    WindowCloseEvent() {}

    EVENT_CLASS_CATEGORY(EventCategoryApplication);
    EVENT_CLASS_TYPE(WindowClose);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "WindowCloseEvent";
        return str.str();
    }

};

class WindowResizeEvent : public Event
{

public:

    WindowResizeEvent(int width, int height) : m_Width(width), m_Height(height) {}

    EVENT_CLASS_CATEGORY(EventCategoryApplication);
    EVENT_CLASS_TYPE(WindowResize);
    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "WindowResizeEvent, width: " << m_Width << ", height: " << m_Height;
        return str.str();
    }
private:
    int m_Width, m_Height;

};
