

#include <chrono>
#include <thread>

#include "core.h"
#include "engine.h"
#include "instrumentation.h"
#include "application.h"

int main(int argc, char* argv[])
{
    PROFILE_BEGIN_SESSION("RunTime", "profiling (open with chrome tracing).json");

    std::shared_ptr<Application> application;
    std::shared_ptr<Engine> engine;

    {
        PROFILE_SCOPE("engine startup");
        engine = std::make_shared<Engine>("./");
        
        if (!engine->Start())
        {
            return -1;
        }
    }
    {
        PROFILE_SCOPE("application startup");
        application = Application::Create();
        if (!application->Start())
        {
            return -1;
        }
    }

    LOG_CORE_INFO("entering main application");
    while (engine->IsRunning())
    {
        {
            PROFILE_SCOPE("OnUpdate()");
            engine->OnUpdate();
            application->OnUpdate();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    application->Shutdown();
    engine->Quit();

    PROFILE_END_SESSION();
};
