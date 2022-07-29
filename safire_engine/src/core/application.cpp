#include "safire/core/application.hpp"

#include "safire/tools/string.hpp"
#include <vector>

namespace safire
{

    void Application::push_layer()
    {
    }

    void Application::run()
    {
        OnEntry();

        OnTermination();
    }

} // namespace safire
