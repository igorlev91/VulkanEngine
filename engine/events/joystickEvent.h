

#pragma once

#include "engine.h"
#include "event.h"

class JoystickAxisMovedEvent : public Event
{

public:

    JoystickAxisMovedEvent(int indexID, int axis, int value)
        : m_IndexID(indexID), m_Axis(axis), m_Value(value) {}
    
    inline int GetJoystickIndexID() const { return m_IndexID; }
    inline int GetAxis()  const { return m_Axis; }
    inline int GetAxisValue() const { return m_Value; }

    EVENT_CLASS_CATEGORY(EventCategoryJoystick);
    EVENT_CLASS_TYPE(JoystickAxisMoved);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "JoystickAxisMovedEvent: " << m_IndexID << ", m_Axis: " << m_Axis << ", m_Value: " << m_Value;
        return str.str();
    }

private:
    
    int m_IndexID, m_Axis, m_Value;

};

class JoystickHatMovedEvent : public Event
{

public:

    JoystickHatMovedEvent(int indexID, int hat, int value)
        : m_IndexID(indexID), m_Hat(hat), m_Value(value) {}
    
    inline int GetJoystickIndexID() const { return m_IndexID; }
    inline int GetHat()  const { return m_Hat; }
    inline int GetHatValue() const { return m_Value; }

    EVENT_CLASS_CATEGORY(EventCategoryJoystick);
    EVENT_CLASS_TYPE(JoystickHatMoved);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "JoystickHatMovedEvent: " << m_IndexID << ", m_Hat: " << m_Hat << ", m_Value: " << m_Value;
        return str.str();
    }

private:
    
    int m_IndexID, m_Hat, m_Value;

};

class JoystickBallMovedEvent : public Event
{

public:

    JoystickBallMovedEvent(int indexID, int hat, int xrel, int yrel)
        : m_IndexID(indexID), m_Ball(hat), m_RelativeX(xrel), m_RelativeY(yrel) {}
    
    inline int GetJoystickIndexID() const { return m_IndexID; }
    inline int GetBall()  const { return m_Ball; }
    inline int GetRelativeX() const { return m_RelativeX; }
    inline int GetRelativeY() const { return m_RelativeY; }

    EVENT_CLASS_CATEGORY(EventCategoryJoystick);
    EVENT_CLASS_TYPE(JoystickBallMoved);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "JoystickBallMovedEvent: " << m_IndexID << ", m_Ball: " << m_Ball << ", m_RelativeX: " << m_RelativeX << ", m_RelativeY: " << m_RelativeY;
        return str.str();
    }

private:
    
    int m_IndexID, m_Ball, m_RelativeX, m_RelativeY;

};

class JoystickButtonEvent : public Event
{

public:
    
    inline int GetJoystickIndexID() const { return m_IndexID; }
    inline int GetJoystickButton()  const { return m_JoystickButton; }
    
    EVENT_CLASS_CATEGORY(EventCategoryJoystick | EventCategoryJoystickButton);

protected:
    JoystickButtonEvent(int indexID, int joystickButton)
        : m_IndexID(indexID), m_JoystickButton(joystickButton) {}
    
private:

    int m_IndexID;
    int m_JoystickButton;

};

class JoystickButtonPressedEvent : public JoystickButtonEvent
{

public:
    JoystickButtonPressedEvent(int indexID, int joystickButton)
        : JoystickButtonEvent(indexID, joystickButton) {}

    EVENT_CLASS_TYPE(JoystickButtonPressed);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "JoystickButtonPressedEvent: " << GetJoystickIndexID() << ", m_JoystickButton: " << GetJoystickButton();
        return str.str();
    }

};

class JoystickButtonReleasedEvent : public JoystickButtonEvent
{

public:
    JoystickButtonReleasedEvent(int indexID, int joystickButton)
        : JoystickButtonEvent(indexID, joystickButton) {}
    
    EVENT_CLASS_TYPE(JoystickButtonReleased);
    
    std::string ToString() const override
    {
        std::stringstream str;
        str << "JoystickButtonReleasedEvent: " << GetJoystickIndexID() << ", m_JoystickButton: " << GetJoystickButton();
        return str.str();
    }

};
