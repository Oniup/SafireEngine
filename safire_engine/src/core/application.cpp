#include "safire/core/application.hpp"

#include "safire/tools/utils.hpp"

namespace safire
{

    Layer* Application::get_layer_at_index(int index) const
    {
        return m_layers[index];
    }

    Layer* Application::get_layer(int id) const
    {
        for (Layer* layer : m_layers)
        {
            if (layer->get_id() == id)
                return layer;
        }

        return nullptr;
    }

    void Application::push_layer(Layer* layer)
    {
        if (layer != nullptr)
            m_layers.push_back(layer);
    }

    void Application::run()
    {
        init_required_layers();
        on_entry();

        on_termination();
        clear_layers();
    }

    void Application::clear_layers()
    {
        for (Layer* layer : m_layers)
        {
            layer->on_detach();
            delete layer;
        }

        m_layers.clear();
    }

    void Application::init_required_layers()
    {
        // TODO: Add the ECS - Pipeline layers
    }

} // namespace safire
