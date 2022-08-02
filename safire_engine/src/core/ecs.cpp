#include "safire/core/ecs.hpp"

namespace safire
{

    void SceneLayer::on_attach()
    {
    }

    void SceneLayer::on_update()
    {
    }

    void SceneLayer::on_detach()
    {
    }

    void SceneLayer::on_imgui()
    {
    }

    void SceneLayer::load_scene(const char* path)
    {
        // TODO: look for scene data file
        // and remove the temporary code here:

        static int temp_id_gen = 0;
        temp_id_gen++;
        m_loaded_scenes.push_back(new Scene);
        m_loaded_scenes.get_last()->id = temp_id_gen;
    }

    void SceneLayer::set_active_scene(const int scene_id)
    {
        
    }

    Entity* SceneLayer::create_entity(int group_id)
    {
        return nullptr;
    }

    DyArray<Entity>::Iterator SceneLayer::create_entities(int group_id, int count)
    {
        return nullptr;
    }

    Component* SceneLayer::create_component(Entity* entity, Component* component)
    {
        return nullptr;
    }

    Component* SceneLayer::create_component(UUID entity_UUID, Component* component)
    {
        return nullptr;
    }

    Component* SceneLayer::create_component_for_all(int group_id, Component* component)
    {
        return nullptr;
    }

    void SceneLayer::destroy_entity(int index)
    {
    }

    void SceneLayer::destroy_entity(UUID entity_UUID)
    {
    }

    void SceneLayer::destroy_entities(int group_id)
    {
    }

    void SceneLayer::destroy_entities_in_range(int start_index, int end_index)
    {
    }

    void SceneLayer::clear()
    {
    }

} // namespace safire
