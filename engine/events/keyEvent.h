

#pragma once

#include "engine.h"
#include "event.h"
#include "keyCodes.h"

class KeyEvent : public Event
{

public:
    
    inline int GetKeyCode() const { return m_KeyCode; }
    
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

protected:
    KeyEvent(int keyCode)
        : m_KeyCode(keyCode) {}

private:

    int m_KeyCode;

};

class KeyPressedEvent : public KeyEvent
{

public:
    KeyPressedEvent(int keyCode)
        : KeyEvent(keyCode)
    {
    }

    EVENT_CLASS_TYPE(KeyPressed);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "KeyPressedEvent: m_KeyCode: " << GetKeyCode();
        return str.str();
    }

};

class KeyReleasedEvent : public KeyEvent
{

public:
    KeyReleasedEvent(int keyCode)
        : KeyEvent(keyCode)
    {
    }
    
    EVENT_CLASS_TYPE(KeyReleased);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "KeyReleasedEvent: m_KeyCode: " << GetKeyCode();
        return str.str();
    }

};
