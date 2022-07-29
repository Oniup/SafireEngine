#include "entry_point.hpp"

int main(int argc, char* argv[])
{
    safire::Application* app = safire::get_application();
    app->run();
    delete app;

    return 0;
}
