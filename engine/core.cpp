

#include <csignal>

#include "core.h"
#include "engine.h"
#include "instrumentation.h"

Engine* Engine::m_Engine = nullptr;

Engine::Engine(const std::string& configFilePath) :
            m_ConfigFilePath(configFilePath),
            m_Running(false)
{
    m_Engine = this;
}

Engine::~Engine()
{
}

bool Engine::Start()
{
    // init logger
    if (!Log::Init())
    {
        std::cout << "Could not initialize logger" << std::endl;
    }

    //signal handling
    signal(SIGINT, SignalHandler);

    
    
    // create main window
    std::string title = "Vulkan Engine v" ENGINE_VERSION;
    WindowProperties windowProperties(title);
    m_Window = Window::Create(windowProperties);
    if (!m_Window->IsOK())
    {
        LOG_CORE_CRITICAL("Could not create main window");
        return false;
    }

    m_Running = true;

    return true;
}

void Engine::Shutdown()
{
    m_Running = false;
}

void Engine::Quit()
{
}

void Engine::OnUpdate()
{
    m_Window->OnUpdate();
    if (!m_Window->IsOK())
    {
        Shutdown();
    }
}

void Engine::OnRender()
{
}

void Engine::SignalHandler(int signal)
{
    if (signal == SIGINT)
    {
        LOG_CORE_INFO("Received signal SIGINT, exiting");
        exit(0);
    }
}
