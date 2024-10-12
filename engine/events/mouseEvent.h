

#pragma once

#include "engine.h"
#include "event.h"

class MouseMovedEvent : public Event
{

public:

    MouseMovedEvent(float x, float y)
        : m_MouseX(x), m_MouseY(y) {}
    
    inline float GetX() const { return m_MouseX; }
    inline float GetY() const { return m_MouseY; }

    EVENT_CLASS_CATEGORY(EventCategoryMouse);
    EVENT_CLASS_TYPE(MouseMoved);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "MouseMovedEvent: m_MouseX: " << m_MouseX << ", m_MouseY: " << m_MouseY;
        return str.str();
    }

private:

    float m_MouseX, m_MouseY;

};

class MouseScrolledEvent : public Event
{

public:

    MouseScrolledEvent(float xOffset, float yOffset)
        : m_MouseOffsetX(xOffset), m_MouseOffsetY(yOffset)
    {
    }
    
    inline float GetX() const { return m_MouseOffsetX; }
    inline float GetY() const { return m_MouseOffsetY; }

    EVENT_CLASS_CATEGORY(EventCategoryMouse);
    EVENT_CLASS_TYPE(MouseScrolled);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "MouseScrolledEvent: m_MouseOffsetX: " << m_MouseOffsetX << ", m_MouseOffsetY " << m_MouseOffsetY;
        return str.str();
    }

private:

    float m_MouseOffsetX, m_MouseOffsetY;

};


class MouseButtonEvent : public Event
{

public:

    enum MouseButtons
    {
        Left,
        Right,
        Middle
    };

public:
    
    inline int GetMouseButton() const { return m_MouseButton; }
    
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton);

protected:
    MouseButtonEvent(int mouseButton)
        : m_MouseButton(mouseButton)
    {
    }

    int m_MouseButton;

};

class MouseButtonPressedEvent : public MouseButtonEvent
{

public:
    MouseButtonPressedEvent(int mouseButton, double posX, double posY)
        : MouseButtonEvent(mouseButton), m_MouseX(posX), m_MouseY(posY)
    {
        
    }
    
    inline int GetButton() const { return m_MouseButton; }
    inline float GetX() const { return m_MouseX; }
    inline float GetY() const { return m_MouseY; }

    EVENT_CLASS_TYPE(MouseButtonPressed);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "MouseButtonPressedEvent: m_MouseButton: " << GetMouseButton();
        return str.str();
    }
    
private:
    double m_MouseX;
    double m_MouseY;

};

class MouseButtonReleasedEvent : public MouseButtonEvent
{

public:
    MouseButtonReleasedEvent(int mouseButton)
        : MouseButtonEvent(mouseButton)
    {
    }
    
    EVENT_CLASS_TYPE(MouseButtonReleased);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "MouseButtonReleasedEvent: m_MouseButton: " << GetMouseButton();
        return str.str();
    }

};
