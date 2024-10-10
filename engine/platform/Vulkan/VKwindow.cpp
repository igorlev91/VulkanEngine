

#include <memory>

#include "VKwindow.h"

bool VK_Window::m_GLFWIsInitialized = false;

VK_Window::VK_Window(const WindowProperties& props)
    : m_OK(false), m_IsFullscreen(false)
{
    m_WindowProperties.m_Title    = props.m_Title;
    m_WindowProperties.m_Width    = props.m_Width;
    m_WindowProperties.m_Height   = props.m_Height;
    //m_WindowProperties.m_VSync    = props.m_VSync;
    //m_WindowProperties.m_MousePosX= 0.0f;
    //m_WindowProperties.m_MousePosY= 0.0f;

    //m_AllowCursor = false;
    if (!m_GLFWIsInitialized)
    {
        // init glfw
        m_GLFWIsInitialized = InitGLFW();
    }
    if (m_GLFWIsInitialized)
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    
        m_Window = glfwCreateWindow(800, 600, props.m_Title.c_str(), nullptr, nullptr);

        uint extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        LOG_CORE_INFO("{0}  extensions supported", extensionCount);

        std::vector<VkExtensionProperties> extensions(extensionCount);
        //populate buffer
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data()); 
        for (auto& extension : extensions)
        {
            LOG_CORE_INFO("extension found: {0}", extension.extensionName);
        }
        if (m_Window) m_OK = true;
    }
    //    int count;
    //    GLFWmonitor** monitors = glfwGetMonitors(&count);
    //    const GLFWvidmode* videoMode = glfwGetVideoMode(monitors[0]);
    //    m_RefreshRate = videoMode->refreshRate;
    //
    //    // make window invisible before it gets created
    //    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    //
    //    int monitorX, monitorY;
    //    glfwGetMonitorPos(monitors[0], &monitorX, &monitorY);
    //
    //    if (m_WindowProperties.m_Width == -1)
    //    {
    //        m_WindowedWidth = videoMode->width / 1.5f;
    //        m_WindowedHeight = m_WindowedWidth / 16 * 9;
    //        m_WindowPositionX = (videoMode->width - m_WindowedWidth) / 2;
    //        m_WindowPositionY = (videoMode->height - m_WindowedHeight) / 2;
    //
    //        if (CoreSettings::m_EnableFullscreen)
    //        {
    //            #ifdef _WIN32    
    //                m_WindowProperties.m_Width = videoMode->width;
    //                m_WindowProperties.m_Height = videoMode->height;
    //                m_Window = glfwCreateWindow(
    //                    m_WindowProperties.m_Width,
    //                    m_WindowProperties.m_Height,
    //                    m_WindowProperties.m_Title.c_str(),
    //                    monitors[0], NULL);
    //                m_IsFullscreen = true;
    //            #else
    //                m_WindowProperties.m_Width  = m_WindowedWidth;
    //                m_WindowProperties.m_Height = m_WindowedHeight;
    //
    //                m_Window = glfwCreateWindow(
    //                    m_WindowProperties.m_Width,
    //                    m_WindowProperties.m_Height,
    //                    m_WindowProperties.m_Title.c_str(),
    //                    NULL, NULL);
    //                // center window
    //                glfwSetWindowPos(m_Window,
    //                    monitorX + m_WindowPositionX,
    //                    monitorY + m_WindowPositionY);
    //                m_IsFullscreen = false;
    //                ToggleFullscreen();
    //            #endif
    //        }
    //        else
    //        {
    //            m_WindowProperties.m_Width  = m_WindowedWidth;
    //            m_WindowProperties.m_Height = m_WindowedHeight;
    //
    //            m_Window = glfwCreateWindow(
    //                        m_WindowProperties.m_Width, 
    //                        m_WindowProperties.m_Height, 
    //                        m_WindowProperties.m_Title.c_str(), 
    //                        NULL, NULL);
    //        }
    //    }
    //    else
    //    {
    //        m_WindowedWidth = m_WindowProperties.m_Width;
    //        m_WindowedHeight = m_WindowProperties.m_Height;
    //        m_WindowPositionX = (videoMode->width - m_WindowedWidth) / 2;
    //        m_WindowPositionY = (videoMode->height - m_WindowedHeight) / 2;
    //
    //        m_WindowProperties.m_Width = m_WindowedWidth;
    //        m_WindowProperties.m_Height = m_WindowedHeight;
    //
    //        m_Window = glfwCreateWindow(
    //            m_WindowProperties.m_Width,
    //            m_WindowProperties.m_Height,
    //            m_WindowProperties.m_Title.c_str(),
    //            NULL, NULL);
    //    }
    //    
    //    if (!m_Window)
    //    {
    //        LOG_CORE_CRITICAL("Failed to create main window");
    //        char description[1024];
    //        int errorCode = glfwGetError((const char **)(&description));
    //
    //        if (errorCode != GLFW_NO_ERROR)
    //        {
    //            LOG_CORE_CRITICAL("glfw error code: {0}", errorCode);
    //        }
    //        glfwTerminate();
    //    }
    //    else
    //    {
    //        if (!CoreSettings::m_EnableFullscreen)
    //        {
    //            // center window
    //            glfwSetWindowPos(m_Window,
    //                monitorX + m_WindowPositionX,
    //                monitorY + m_WindowPositionY);
    //        }
    //        
    //        
    //        // make the window visible
    //        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    //        glfwShowWindow(m_Window);
    //
    //        // set app icon
    //        GLFWimage icon;
    //        size_t fileSize;
    //        const uchar* data = (const uchar*) ResourceSystem::GetDataPointer(fileSize, "/images/atlas/images/I_ENGINE.png", IDB_ENGINE_LOGO, "PNG");
    //        icon.pixels = stbi_load_from_memory(data, fileSize, &icon.width, &icon.height, 0, 4); //rgba channels
    //        if (icon.pixels) 
    //        {
    //            glfwSetWindowIcon(m_Window, 1, &icon); 
    //            stbi_image_free(icon.pixels);
    //        }
    //        else
    //        {
    //            LOG_CORE_WARN("Could not load app icon");
    //        }
    //        
    //        m_GraphicsContext = GraphicsContext::Create(m_Window, m_RefreshRate);
    //        if (!m_GraphicsContext->Init())
    //        {
    //            LOG_CORE_CRITICAL("Could not create a rendering context");
    //            
    //        }
    //        else
    //        {
    //            SetVSync(props.m_VSync);
    //        }
    //
    //        // init glew
    //        if (InitGLEW())
    //        {
    //            // all good
    //            m_OK = true;
    //        }
    //    }
    //}
}

VK_Window::~VK_Window()
{
    Shutdown();
}

void VK_Window::Shutdown()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

//void VK_Window::SetVSync(int interval)
//{ 
//    m_WindowProperties.m_VSync = interval;
//    m_GraphicsContext->SetVSync(interval);
//}
//
//void VK_Window::ToggleFullscreen()
//{ 
//    int count;
//    GLFWmonitor** monitors = glfwGetMonitors(&count);
//    const GLFWvidmode* videoMode = glfwGetVideoMode(monitors[0]);
//    if (m_IsFullscreen)
//    {
//        m_WindowProperties.m_Width  = m_WindowedWidth;
//        m_WindowProperties.m_Height = m_WindowedHeight;
//
//        glfwSetWindowMonitor(m_Window, nullptr, m_WindowPositionX, m_WindowPositionY, m_WindowedWidth, m_WindowedHeight, videoMode->refreshRate);
//        glfwSetWindowPos(m_Window, m_WindowPositionX, m_WindowPositionY);
//    }
//    else
//    {
//        m_WindowedWidth = m_WindowProperties.m_Width; 
//        m_WindowedHeight = m_WindowProperties.m_Height;
//        glfwGetWindowPos(m_Window, &m_WindowPositionX, &m_WindowPositionY);
//
//        glfwSetWindowMonitor(m_Window, monitors[0], 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);
//    }
//    m_IsFullscreen = !m_IsFullscreen;
//}
//
//void VK_Window::SetWindowAspectRatio()
//{
//    // set aspect ratio to current ratio
//    int numer = m_WindowProperties.m_Width;
//    int denom = m_WindowProperties.m_Height;
//    glfwSetWindowAspectRatio(m_Window, numer, denom);
//}
//
//void VK_Window::SetWindowAspectRatio(int numer, int denom)
//{
//    glfwSetWindowAspectRatio(m_Window, numer, denom);
//}

void VK_Window::OnUpdate()
{
    if (glfwWindowShouldClose(m_Window))
    {
        m_OK = false;
    }
    else
    {
        glfwPollEvents();
    }
}

//void VK_Window::OnError(int errorCode, const char* description) 
//{
//        LOG_CORE_CRITICAL("GLEW error, code: {0}, description: {1}", std::to_string(errorCode), description);
//
//}
//
//void VK_Window::SetEventCallback(const EventCallbackFunction& callback)
//{
//    m_WindowProperties.m_EventCallback = callback;
//    glfwSetWindowUserPointer(m_Window,&m_WindowProperties);
//    
//    glfwSetErrorCallback([](int errorCode, const char* description) { VK_Window::OnError(errorCode, description);});
//    
//    glfwSetKeyCallback(m_Window,[](GLFWwindow* window, int key, int scancode, int action, int modes)
//        {
//            WindowData& windowProperties = *(WindowData*)glfwGetWindowUserPointer(window);
//            EventCallbackFunction OnEvent = windowProperties.m_EventCallback;
//            
//            switch (action)
//            {
//                case GLFW_PRESS:
//                {
//                    KeyPressedEvent event(key);
//                    OnEvent(event);
//                    break;
//                }
//                case GLFW_RELEASE:
//                {
//                    KeyReleasedEvent event(key);
//                    OnEvent(event);
//                    break;
//                }
//                case GLFW_REPEAT:
//                    break;
//            }
//        }
//    );
//    
//    glfwSetWindowCloseCallback(m_Window,[](GLFWwindow* window)
//        {
//            WindowData& windowProperties = *(WindowData*)glfwGetWindowUserPointer(window);
//            EventCallbackFunction OnEvent = windowProperties.m_EventCallback;
//                
//            WindowCloseEvent event;
//            OnEvent(event);
//        }
//    );
//
//    glfwSetWindowSizeCallback(m_Window,[](GLFWwindow* window, int width, int height)
//        {
//            WindowData& windowProperties = *(WindowData*)glfwGetWindowUserPointer(window);
//            EventCallbackFunction OnEvent = windowProperties.m_EventCallback;
//            
//            windowProperties.m_Width = width;
//            windowProperties.m_Height = height;
//                
//            WindowResizeEvent event(width, height);
//            OnEvent(event);
//        }
//    );
//
//    glfwSetFramebufferSizeCallback(m_Window,[](GLFWwindow* window, int width, int height)
//        {
//            GLCall(glViewport(0, 0, width, height));
//        }
//    );
//
//    glfwSetWindowIconifyCallback(m_Window,[](GLFWwindow* window, int iconified)
//        {
//            int width, height;
//            WindowData& windowProperties = *(WindowData*)glfwGetWindowUserPointer(window);
//            EventCallbackFunction OnEvent = windowProperties.m_EventCallback;
//            
//            if (iconified)
//            {
//                width = height = 0;
//            }
//            else
//            {
//                glfwGetWindowSize(window, &width, &height);
//            }
//            
//            windowProperties.m_Width = width;
//            windowProperties.m_Height = height;
//                
//            WindowResizeEvent event(width, height);
//            OnEvent(event);
//        }
//    );
//
//    glfwSetMouseButtonCallback(m_Window,[](GLFWwindow* window, int button, int action, int mods)
//        {
//            WindowData& windowProperties = *(WindowData*)glfwGetWindowUserPointer(window);
//            EventCallbackFunction OnEvent = windowProperties.m_EventCallback;
//            
//            switch (action)
//            {
//                case GLFW_PRESS:
//                {
//                    MouseButtonPressedEvent event(button,windowProperties.m_MousePosX,windowProperties.m_MousePosY);
//                    OnEvent(event);
//                    break;
//                }
//                case GLFW_RELEASE:
//                {
//                    MouseButtonReleasedEvent event(button);
//                    OnEvent(event);
//                    break;
//                }
//            }
//        }
//    );
//    
//    glfwSetCursorPosCallback(m_Window,[](GLFWwindow* window, double xpos, double ypos)
//        {
//            WindowData& windowProperties = *(WindowData*)glfwGetWindowUserPointer(window);
//            EventCallbackFunction OnEvent = windowProperties.m_EventCallback;
//            
//            windowProperties.m_MousePosX = xpos;
//            windowProperties.m_MousePosY = ypos;
//                        
//            MouseMovedEvent event(xpos, ypos);
//            OnEvent(event);
//            
//        }
//    );
//    
//    glfwSetScrollCallback(m_Window,[](GLFWwindow* window, double xoffset, double yoffset)
//        {
//            WindowData& windowProperties = *(WindowData*)glfwGetWindowUserPointer(window);
//            EventCallbackFunction OnEvent = windowProperties.m_EventCallback;
//                        
//            MouseScrolledEvent event(xoffset, yoffset);
//            OnEvent(event);
//            
//        }
//    );
//}

bool VK_Window::InitGLFW()
{
    
    // init glfw
    if (!glfwInit())
    {
        LOG_CORE_CRITICAL("glfwInit() failed");
        return false;
    }

    return true;
}

//void VK_Window::EnableMousePointer()
//{
//    if (m_AllowCursor)
//    {
//        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//    }
//}
//
//void VK_Window::DisableMousePointer()
//{
//    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
//}
//
//void VK_Window::AllowCursor()
//{
//    m_AllowCursor = true;
//}
//void VK_Window::DisallowCursor()
//{
//    m_AllowCursor = false;
//    DisableMousePointer();
//}
