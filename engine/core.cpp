

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

    glfwInit();
    
    // create main window
    std::string title = "Vulkan Engine v" ENGINE_VERSION;
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_Window = glfwCreateWindow(800, 600, title.c_str(), nullptr, nullptr);

    uint extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    LOG_CORE_INFO("{0}  extensions supported", extensionCount);

    m_Running = true;

    return true;
}

void Engine::Shutdown()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
    m_Running = false;
}

void Engine::Quit()
{
}

void Engine::OnUpdate()
{
    if (glfwWindowShouldClose(m_Window))
    {
        Shutdown();
    }
    else
    {
        glfwPollEvents();
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
