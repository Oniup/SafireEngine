#ifndef SAFIRE_ENTITY_HPP
#define SAFIRE_ENTITY_HPP

#include "safire/tools/utils.hpp"

namespace safire
{

    class Component
    {
      public:
        UUID uuid;
        uint32_t id;

      public:
        virtual void on_attach()
        {
        }

        virtual void on_detach()
        {
        }

        virtual void on_update()
        {
        }

        virtual void on_late_update()
        {
        }

        virtual void on_fixed_update()
        {
        }
    };

    struct Entity
    {
        UUID uuid;
        int group_id;
        DyArray<Component*> components;
    };

} // namespace safire

#endif // SAFIRE_ENTITY_HPP
