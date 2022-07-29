#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "safire/tools/utils.hpp"

namespace safire
{

    class Application
    {
      public:
        virtual ~Application()
        {
        }

      public:
        virtual void OnEntry()
        {
        }
        virtual void OnTermination()
        {
        }

        void push_layer(); // TODO: add utils functions first

        void run();

      protected:
    };

    extern Application* get_application();

} // namespace safire

#endif // APPLICATION_HPP

/*
Safire Engine Change log

    (30/07/2022)            * Implement of basic String class
                            * Started development of the main application handler
                            * Added a sandbox demo project
                            * Started low level memory functions

*/
