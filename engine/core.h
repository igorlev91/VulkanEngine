

#pragma once

#include <memory>
#include <string>

#include "event.h"
#include "engine.h"
#include "window.h"
#include "audio.h"

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
    double GetTime() const { return m_Window->GetTime(); }

    static Engine* m_Engine;

private:
    static void SignalHandler(int signal);
    void ToggleFullscreen();

private:
    
    std::string m_ConfigFilePath;
    std::shared_ptr<Window> m_Window;
    std::shared_ptr<Audio> m_Audio;

    bool m_Running;

};
