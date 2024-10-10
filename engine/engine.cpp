

#include <chrono>
#include <thread>

#include "core.h"
#include "engine.h"
#include "instrumentation.h"
#include "application.h"

int main(int argc, char* argv[])
{
    PROFILE_BEGIN_SESSION("RunTime", "profiling (open with chrome tracing).json");

    Engine engine("./");
    if (!engine.Start())
    {
        return -1;
    }

    std::shared_ptr<Application> application = Application::Create();
    if (!application->Start())
    {
        return -1;
    }

    LOG_CORE_INFO("entering main application");
    while (engine.IsRunning())
    {
        application->OnUpdate();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    application->Shutdown();

    engine.Quit();

    PROFILE_END_SESSION();
};
