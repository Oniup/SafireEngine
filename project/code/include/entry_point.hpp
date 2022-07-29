#ifndef SANDBOX_ENTRY_POINT_HPP
#define SANDBOX_ENTRY_POINT_HPP

#include "safire/core/application.hpp"

class SandboxApp : public safire::Application
{
  public:
    SandboxApp();
    ~SandboxApp();

  public:
    virtual void OnEntry() override;
    virtual void OnTermination() override;
};

#endif // SANDBOX_ENTRY_POINT_HPP
