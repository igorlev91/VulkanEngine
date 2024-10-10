
#include "window.h"
#include "rendererAPI.h"
#include "VKwindow.h"

std::unique_ptr<Window> Window::Create(const WindowProperties& props)
{
    std::unique_ptr<Window> m_Window;

    switch(RendererAPI::GetAPI())
    {
        case RendererAPI::VULKAN:
            m_Window = std::make_unique<VK_Window>(props);
            break;
        default:
            m_Window = nullptr;
            break;
    }

    return m_Window;
}
