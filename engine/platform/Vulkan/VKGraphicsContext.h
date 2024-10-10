

#pragma once

#include "engine.h"
#include "graphicsContext.h"

#include "VKwindow.h"
#include "VKpipeline.h"

class VKContext : public GraphicsContext
{
public:

    VKContext(GLFWwindow* window, uint refreshRate);

    virtual bool Init() override;
    virtual void SetVSync(int interval) override;
    virtual void SwapBuffers() override;
    virtual bool IsInitialized() const override { return m_Initialized; }

private:

    bool m_Initialized;
    GLFWwindow* m_Window;
    VK_Pipeline m_Pipeline{"bin/simpleShader.vert.spv", "bin/simpleShader.frag.spv"};
    uint m_RefreshRate; // frames per second
    uint m_MicroSecondsPerFrame; // (in micro seconds)
    
    int m_VSync;
    int m_VSyncIsWorking = 10; // gets decremented if not working
    double m_StartTime;

};
    
