#ifndef SANDBOX_ENTRY_POINT_HPP
#define SANDBOX_ENTRY_POINT_HPP

#include "safire/core/application.hpp"

class SandboxApp : public safire::Application
{
  public:
    SandboxApp();
    ~SandboxApp();

  public:
    virtual void on_entry() override;
    virtual void on_termination() override;
};

#endif // SANDBOX_ENTRY_POINT_HPP
