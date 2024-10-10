

#pragma once

#include <memory>

class Application
{

public:

    Application();
    ~Application() {}

    bool Start();
    void Shutdown();
    void OnUpdate();
    
    static std::shared_ptr<Application> Create();

private:

    static void ConsoleInputHandler();

private:

    static std::shared_ptr<Application> m_Instance;

};
