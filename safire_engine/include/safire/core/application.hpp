#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "safire/tools/utils.hpp"
#include "safire/core/layer.hpp"

namespace safire
{

    class PipelineLayer;
    class EcsLayer;

    class Application
    {
      public:
        virtual ~Application()
        {
        }

      public:
        virtual void on_entry()
        {
        }

        virtual void on_termination()
        {
        }

        Layer* get_layer_at_index(int index) const;
        Layer* get_layer(int id) const;

        void push_layer(Layer* layer);

        void run();

      protected:
        void clear_layers();

      protected:
        DyArray<Layer*> m_layers;
        PipelineLayer* m_pipeline;
        EcsLayer* m_ecs;

      private:
        void init_required_layers();
    };

    extern Application* get_application();

} // namespace safire

#endif // APPLICATION_HPP

/*
Safire Engine Change log

    v0.0.3 - (2/08/2022)            * Updated .clang-format so that it wouldn't order includes so it doesn't break glad
and glfw
                                    * Started Development on the EcsLayer
                                        * Designed how Scenes will be created and how they are going to handle entities and components
                                    * Implemented Layer class
    v0.0.2 - (1/08/2022)            * Implemented Dynamic Array class with iterators
    V0.0.1 - (30/07/2022)           * Implement of basic String class
                                    * Started development of the main application handler
                                    * Added a sandbox demo project
                                    * Started low level memory functions
*/
