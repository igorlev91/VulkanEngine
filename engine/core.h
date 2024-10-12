
#pragma once

#include <memory>
#include <string>

#include "engine.h"
#include "window.h"
#include "event.h"

class Engine
{
public:


public:

    Engine(const std::string& configFilePath);
    ~Engine();

    bool Start();
    void OnUpdate();
    void OnEvent(Event& event);
    void OnRender();
    void Shutdown();
    void Quit();

    bool IsRunning() const { return m_Running; }
    std::string GetConfigFilePath() const { return m_ConfigFilePath; }
    std::shared_ptr<Window> GetWindow() const { return m_Window; }

    static Engine* m_Engine;

private:
    static void SignalHandler(int signal);
    void ToggleFullscreen();

private:
    
    std::string m_ConfigFilePath;
    std::shared_ptr<Window> m_Window;

    bool m_Running;

};
