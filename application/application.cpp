
   
#include <thread>

#include "core.h"
#include "engine.h"
#include "application.h"

std::shared_ptr<Application> Application::m_Instance;

Application::Application()
{
}

bool Application::Start()
{
    std::thread consoleInputHandler(ConsoleInputHandler);
    consoleInputHandler.detach();

    return true;
}

void Application::Shutdown()
{
}

void Application::OnUpdate()
{
}

std::shared_ptr<Application> Application::Create()
{
    if (!m_Instance)
    {
        m_Instance = std::make_shared<Application>();
    }
    return m_Instance;
}

void Application::ConsoleInputHandler()
{
    while (true)
    {
        LOG_APP_INFO("press enter to exit");
        getchar(); // block until enter is pressed
        Engine::m_Engine->Shutdown();
        break;
    }

}
