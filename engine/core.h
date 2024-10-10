

#pragma one

#include <string>

class Engine
{
public:


public:

    Engine(const std::string& configFilePath);
    ~Engine();

    bool Start();
    void OnUpdate();
    void OnRender();
    void Shutdown(bool switchOffComputer = false);
    void Quit();

    void InitSettings();

    bool IsRunning() const { return m_Running; }
    std::string GetConfigFilePath() const { return m_ConfigFilePath; }

    static Engine* m_Engine;

private:
    static void SignalHandler(int signal);

private:
    
    std::string m_ConfigFilePath;

    bool m_Running;

};
