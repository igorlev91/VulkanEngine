

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

    m_Running = false;
    // init logger
    if (!Log::Init())
    {
        std::cout << "Could not initialize logger" << std::endl;
    }

    InitSettings();

    // create main window
    std::string title = "Vulkan Engine v" ENGINE_VERSION;
    
    m_Running = true;

    signal(SIGINT, SignalHandler);

    return true;
}

void Engine::Shutdown(bool switchOffComputer)
{
    m_Running = false;
}

void Engine::Quit()
{
}

void Engine::OnUpdate()
{
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

void Engine::InitSettings()
{
}

