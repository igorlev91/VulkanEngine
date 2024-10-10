

#pragma once

#include <memory>

class GraphicsContext
{
public:

    virtual bool Init() = 0;
    virtual void SetVSync(int interval) = 0;
    virtual void SwapBuffers() = 0;
    virtual bool IsInitialized() const = 0;
    
    static std::shared_ptr<GraphicsContext> Create(void* window, uint refreshRate);

private: 

};
