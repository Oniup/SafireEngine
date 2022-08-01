#include "entry_point.hpp"

SandboxApp::SandboxApp()
{
}

SandboxApp::~SandboxApp()
{
}

void SandboxApp::OnEntry()
{
    printf("Creating Sandbox Application\n");
}

void SandboxApp::OnTermination()
{
    printf("\n\nTerminating Sandbox Application\n\n");
}

safire::Application* safire::get_application()
{
    static SandboxApp* app = new SandboxApp();

    return app;
}
