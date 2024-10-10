

#pragma once

#include "engine.h"
#include "window.h"
#include "VKdevice.h"
#include "VKpipeline.h"

#define GLFW_INCLUDE_VULKAN
#include "glfw/include/GLFW/glfw3.h"

class VK_Window : public Window
{

public:

    VK_Window(const WindowProperties& props);
    ~VK_Window() override;

    VK_Window(const VK_Window&) = delete;
    VK_Window& operator=(const VK_Window&) = delete;

    //
    bool InitGLFW();
    void Shutdown();
    void CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
    //void* GetWindow() const override { return (void*)m_Window; }
    //std::shared_ptr<GraphicsContext> GetGraphicsContent() const override { return m_GraphicsContext; }
    void OnUpdate() override;    
    uint GetWidth()  const override { return m_WindowProperties.m_Width; }
    uint GetHeight() const override { return m_WindowProperties.m_Height; }
    //
    //void SetEventCallback(const EventCallbackFunction& callback) override;
    //void SetVSync(int interval) override;
    //void ToggleFullscreen() override;
    //bool IsFullscreen() override { return m_IsFullscreen; }
    bool IsOK() const override { return m_OK; }
    //void SetWindowAspectRatio() override;
    //void SetWindowAspectRatio(int numer, int denom) override;
    float GetWindowAspectRatio() const override { return m_WindowProperties.m_Width / (1.0f * m_WindowProperties.m_Height); }
    //double GetTime() const override { return glfwGetTime(); }
    //
    //static void OnError(int errorCode, const char* description);
    //
    //void EnableMousePointer() override;
    //void DisableMousePointer() override;
    //virtual void AllowCursor() override;
    //virtual void DisallowCursor() override;

protected:

private:

    GLFWwindow* m_Window;

    struct WindowData
    {
        std::string m_Title;
        int m_Width;
        int m_Height;
        //int m_VSync;
        //EventCallbackFunction m_EventCallback;
        //double m_MousePosX;
        //double m_MousePosY;
    };

    static bool m_GLFWIsInitialized;
    //
    bool m_OK;

    WindowData m_WindowProperties;
    std::shared_ptr<VK_Device> m_Device;
    std::shared_ptr<VK_Pipeline> m_Pipeline;

    uint m_RefreshRate;
    bool m_IsFullscreen;

    //int m_WindowedWidth, m_WindowedHeight;
    //int m_WindowPositionX, m_WindowPositionY;
    //bool m_AllowCursor;
};
