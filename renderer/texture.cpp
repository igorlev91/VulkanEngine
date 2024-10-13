

#include "rendererAPI.h"
#include "texture.h"

std::shared_ptr<Texture> Texture::Create()
{
    std::shared_ptr<Texture> texture;

    switch(RendererAPI::GetAPI())
    {
        case RendererAPI::OPENGL:
            texture = nullptr;
            break;
        default:
            texture = nullptr;
            break;
    }

    return texture;
}
std::shared_ptr<Texture> Texture::Create(uint ID, int internalFormat, int dataFormat, int type)
{
    std::shared_ptr<Texture> texture;

    switch(RendererAPI::GetAPI())
    {
        case RendererAPI::OPENGL:
            texture = nullptr;
            break;
        default:
            texture = nullptr;
            break;
    }

    return texture;
}
