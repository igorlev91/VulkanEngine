

#include "rendererAPI.h"
//#include "renderCommand.h"
//#include "GLrendererAPI.h"

RendererAPI::API RendererAPI::s_API = RendererAPI::API::VULKAN;

//void RendererAPI::Create()
//{
//    switch(RendererAPI::GetAPI())
//    {
//        case RendererAPI::OPENGL:
//            RenderCommand::s_RendererAPI = std::make_unique<GLRendererAPI>();
//            break;
//        default:
//            RenderCommand::s_RendererAPI = nullptr;
//            break;
//    }
//}




