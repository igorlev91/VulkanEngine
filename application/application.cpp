
   
#include <thread>

#include "core.h"
#include "engine.h"
#include "application.h"

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
    return std::make_shared<Application>();
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
