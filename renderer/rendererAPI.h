

#pragma once

//#include <memory>
//
//#include "engine.h"
//
//#include "vertexArray.h"
//#include "glm.hpp"

class RendererAPI
{
public:

    enum API
    {
        OPENGL,
        VULKAN
    };
    
public:
    
    //virtual ~RendererAPI() = default;
    //
    //virtual void SetClearColor(const glm::vec4& color) = 0;
    //virtual void Clear() const = 0;
    //virtual void EnableBlending() const = 0;
    //virtual void DisableBlending() const = 0;
    //virtual void EnableDethTesting() const = 0;
    //virtual void DisableDethTesting() const = 0;
    //virtual void EnableScissor() const = 0;
    //virtual void DisableScissor() const = 0;
    //virtual void SetScissor(int left, int bottom, int width, int height) const = 0;
    //
    //virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) const = 0;
    //
    //static void Create();
    //
    //static void SetAPI(API api) { s_API = api;}
    static API GetAPI() { return s_API;}
    
private:
    
    static API s_API;
    
};
