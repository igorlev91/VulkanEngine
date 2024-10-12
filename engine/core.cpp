

#include <csignal>

#include "core.h"
#include "engine.h"
#include "instrumentation.h"
#include "applicationEvent.h"
#include "keyEvent.h"

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
    m_Window->SetEventCallback([this](Event& event){ return this->OnEvent(event); });

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

void Engine::OnEvent(Event& event)
{
    EventDispatcher dispatcher(event);

    // log events
    //if (event.GetCategoryFlags() & EventCategoryApplication) LOG_CORE_INFO(event);
    //if (event.GetCategoryFlags() & EventCategoryInput)       LOG_CORE_INFO(event);
    //if (event.GetCategoryFlags() & EventCategoryMouse)       LOG_CORE_INFO(event);
    //if (event.GetCategoryFlags() & EventCategoryController)  LOG_CORE_INFO(event);
    //if (event.GetCategoryFlags() & EventCategoryJoystick)    LOG_CORE_INFO(event);

    // dispatch to Engine
    //dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent event)
    //    {
    //        Shutdown();
    //        return true;
    //    }
    //);

    dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent event)
        {
            //RenderCommand::SetScissor(0, 0, event.GetWidth(), event.GetHeight());
            //m_WindowScale = GetWindowWidth() / GetContextWidth();
            if ((event.GetWidth() == 0) || (event.GetHeight() == 0))
            {
                LOG_CORE_INFO("application paused");
                //m_Paused = true;
            }
            else
            {
                //m_Paused = false;
            }
            return true;
        }
    );

    dispatcher.Dispatch<KeyPressedEvent>([this](KeyPressedEvent event)
        {
            switch(event.GetKeyCode())
            {
                case ENGINE_KEY_F:
                    LOG_CORE_INFO("toggle fullscreen");
                    //ToggleFullscreen();
                    break;
            }
            return false;
        }
    );

    //dispatcher.Dispatch<MouseMovedEvent>([this](MouseMovedEvent event)
    //    {
    //        m_Window->EnableMousePointer();
    //        m_DisableMousePointerTimer.Stop();
    //        m_DisableMousePointerTimer.Start();
    //        return true;
    //    }
    //);
    //
    //// also dispatch to application
    //// and its layers
    //if (!event.IsHandled())
    //{
    //    for (auto layerIterator = m_LayerStack.end(); layerIterator != m_LayerStack.begin(); )
    //    {
    //        layerIterator--;
    //        (*layerIterator)->OnEvent(event);
    //
    //        if (event.IsHandled()) break;
    //    }
    //}
    //if (!event.IsHandled()) m_AppEventCallback(event);
}
