

#pragma once

#include <functional>
#include <memory>

#include "engine.h"
#include "event.h"

typedef std::function<void(Event&)> EventCallbackFunction;

struct WindowProperties
{
    std::string m_Title;
    int m_Width;
    int m_Height;
    int m_VSync;

    WindowProperties(const std::string& title = "", const bool vsync = 1 /*true*/,
                     const int width = -1, const int height = -1)
        : m_Title(title), m_VSync(vsync), m_Width(width), m_Height(height)
    {
    }
};

class Window
{
    
public:
    
    Window() {}
    virtual ~Window() {}
    
    virtual void* GetWindow() const = 0;
    virtual bool  IsOK() const = 0;
    virtual float GetWindowAspectRatio() const = 0;
    virtual void  SetWindowAspectRatio() = 0;
    virtual void  SetWindowAspectRatio(int numer, int denom) = 0;
    virtual void  OnUpdate() = 0;
    virtual uint  GetWidth() const = 0;
    virtual uint  GetHeight() const = 0;
    //virtual std::shared_ptr<GraphicsContext> GetGraphicsContent() const = 0;
    virtual double GetTime() const = 0;
    //
    virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
    //virtual void SetVSync(int interval) = 0;
    virtual void ToggleFullscreen() = 0;
    virtual bool IsFullscreen() = 0;

    virtual void EnableMousePointer() = 0;
    virtual void DisableMousePointer() = 0;
    virtual void AllowCursor() = 0;
    virtual void DisallowCursor() = 0;
    
    static std::unique_ptr<Window> Create(const WindowProperties& props);

protected:
    
private:
    
};
