#ifndef SAFIRE_ECS_HPP
#define SAFIRE_ECS_HPP

#include "safire/tools/utils.hpp"
#include "safire/core/layer.hpp"
#include "safire/component/entity.hpp"

namespace safire
{

    struct Scene
    {
        int id;
        DyArray<Entity> entities;
        DyArray<Component*> components;
    };

    class SceneLayer : public Layer
    {
      public:
        SceneLayer() = default;
        ~SceneLayer() = default;

      public:
        virtual void on_attach() override;
        virtual void on_update() override;
        virtual void on_detach() override;
        virtual void on_imgui() override;

        inline const Scene* get_scene() const 
        {
            return m_active_scene;
        }

        inline const DyArray<Scene*>* get_loaded_scenes() const
        {
            return &m_loaded_scenes;
        }

        void load_scene(const char* path);
        void set_active_scene(const int scene_id);

        Entity* create_entity(int group_id);
        DyArray<Entity>::Iterator create_entities(int group_id, int count);

        Component* create_component(Entity* entity, Component* component);
        Component* create_component(UUID entity_UUID, Component* component);
        Component* create_component_for_all(int group_id, Component* component);

        void destroy_entity(int index);
        void destroy_entity(UUID entity_UUID);
        void destroy_entities(int group_id);
        void destroy_entities_in_range(int start_index, int end_index);

        void clear();

      private:
        DyArray<Scene*> m_loaded_scenes;
        Scene* m_active_scene;
    };

} // namespace safire

#endif // SAFIRE_ECS_HPP
