#ifndef SAFIRE_LAYER_HPP
#define SAFIRE_LAYER_HPP

namespace safire
{

    class Layer
    {
      public:
        virtual ~Layer();

      public:
        inline int get_id()
        {
            return m_id;
        }

        virtual void on_attach()
        {
        }

        virtual void on_detach()
        {
        }

        virtual void on_update()
        {
        }

        virtual void on_render()
        {
        }

        virtual void on_imgui()
        {
        }

      protected:
        int m_id;
    };

} // namespace safire

#endif // SAFIRE_LAYER_HPP
