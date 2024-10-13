

#include "input.h"
#include "controllerEvent.h"

Controller* Input::m_Controller;

void Input::Start(Controller* controller)
{
    m_Controller = controller;
}

void Input::StartControllerConfig(int controllerID)
{
    m_Controller->StartConfig(controllerID);
}

glm::vec2 Input::GetControllerStick(const int indexID, Controller::ControllerSticks stick)
{
    float x = 0;
    float y = 0;
    if (m_Controller->GetCount() && !m_Controller->ConfigIsRunning())
    {
        auto gameController = m_Controller->GetGameController(indexID);
    
        if (stick == Controller::LEFT_STICK)
        {
            x = SDL_GameControllerGetAxis(gameController, static_cast<SDL_GameControllerAxis>(Controller::LEFT_STICK_HORIZONTAL)) / (1.0f * 32768);
            y = -SDL_GameControllerGetAxis(gameController, static_cast<SDL_GameControllerAxis>(Controller::LEFT_STICK_VERTICAL))   / (1.0f * 32768);
        }
        else if (stick == Controller::RIGHT_STICK)
        {
            x = SDL_GameControllerGetAxis(gameController, static_cast<SDL_GameControllerAxis>(Controller::RIGHT_STICK_HORIZONTAL)) / (1.0f * 32768);
            y = -SDL_GameControllerGetAxis(gameController, static_cast<SDL_GameControllerAxis>(Controller::RIGHT_STICK_VERTICAL))   / (1.0f * 32768);
        }
    }

    return { x, y };
}

float Input::GetControllerTrigger(const int indexID, Controller::Axis trigger)
{
    float x = 0;
    if (m_Controller->GetCount() && !m_Controller->ConfigIsRunning())
    {
        auto gameController = m_Controller->GetGameController(indexID);
    
        if (trigger == Controller::LEFT_TRIGGER)
        {
            x = SDL_GameControllerGetAxis(gameController, static_cast<SDL_GameControllerAxis>(Controller::LEFT_TRIGGER)) / (1.0f * 32768);
        }
        else if (trigger == Controller::RIGHT_TRIGGER)
        {
            x = SDL_GameControllerGetAxis(gameController, static_cast<SDL_GameControllerAxis>(Controller::RIGHT_TRIGGER)) / (1.0f * 32768);
        }
    }
    
    return x;
}

bool Input::IsControllerButtonPressed(const int indexID, const Controller::ControllerCode button)
{
    if (m_Controller->GetCount() && !m_Controller->ConfigIsRunning())
    {
        auto gameController = m_Controller->GetGameController(indexID);
        
        return SDL_GameControllerGetButton(gameController, static_cast<SDL_GameControllerButton>(button));
    }
    else
    {
        return false;
    }
}

uint Input::GetControllerCount()
{
    return m_Controller->GetCount();
}

int Input::GetActiveController()
{
    return m_Controller->GetActiveController();
}

bool Input::ConfigurationRunning()
{
    return m_Controller->ConfigIsRunning();
}

int Input::GetConfigurationStep()
{
    return m_Controller->GetConfigurationStep();
}

int Input::GetConfigurationActiveController()
{
    return m_Controller->GetConfigurationActiveController();
}

int Input::ControllerMappingCreated()
{
    return m_Controller->MappingCreated();
}

std::string Input::GetControlerName(int controllerID)
{
    return m_Controller->GetName(controllerID);
}

void Input::GetControllerGUID(int controllerID, std::string& guid)
{
    m_Controller->GetGUID(controllerID, guid);
}


void* Input::GetControllerJoy(const int indexID)
{
    return m_Controller->GetJoystick(indexID);
}

void* Input::GetControllerGamecontroller(const int indexID)
{
    return m_Controller->GetGameController(indexID);
}
