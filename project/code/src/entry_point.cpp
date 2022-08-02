#include "entry_point.hpp"

SandboxApp::SandboxApp()
{
}

SandboxApp::~SandboxApp()
{
}

void SandboxApp::on_entry()
{
    printf("Creating Sandbox Application\n");
}

void SandboxApp::on_termination()
{
    printf("\n\nTerminating Sandbox Application\n\n");
}

safire::Application* safire::get_application()
{
    static SandboxApp* app = new SandboxApp();

    return app;
}
