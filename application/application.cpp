

#include "application.h"

Application::Application()
{
}

bool Application::Start()
{
    return true;
}

void Application::Shutdown()
{
}

void Application::OnUpdate()
{
}

std::shared_ptr<Application> Application::Create()
{
    return std::make_shared<Application>();
}
