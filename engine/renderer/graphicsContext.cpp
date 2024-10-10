

#include "rendererAPI.h"
#include "graphicsContext.h"
#include "VKGraphicsContext.h"

std::shared_ptr<GraphicsContext> GraphicsContext::Create(void* window, uint refreshRate)
{
    std::shared_ptr<GraphicsContext> graphicsContext;

    switch(RendererAPI::GetAPI())
    {
        case RendererAPI::VULKAN:
            graphicsContext = std::make_shared<VKContext>(static_cast<GLFWwindow*>(window), refreshRate);
            break;
        default:
            graphicsContext = nullptr;
            break;
    }

    return graphicsContext;
}

