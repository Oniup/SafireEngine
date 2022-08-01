// FIXME: this will later be refactored so that it can use COW to improve performance, I just coulnd't be bothered doing
// that now or maybe I won't change this at all

#ifndef SAFIRE_DYNAMIC_ARRAY_HPP
#define SAFIRE_DYNAMIC_ARRAY_HPP

#include "safire/tools/memory.hpp"

#include <initializer_list>

namespace safire
{

    template <typename DyArrayT>
    class DyArrayIterator
    {
      public:
        using value_type = typename DyArrayT::value_type;
        using ptr_type = value_type*;
        using ref_type = value_type&;

      public:
        inline DyArrayIterator(ptr_type ptr) : m_ptr(ptr)
        {
        }

        inline DyArrayIterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        inline DyArrayIterator& operator--()
        {
            m_ptr--;
            return *this;
        }

        inline DyArrayIterator operator++(int)
        {
            DyArrayIterator it = *this;
            ++(*this);
            return it;
        }

        inline DyArrayIterator operator--(int)
        {
            DyArrayIterator it = *this;
            --(*this);
            return it;
        }

        inline ref_type operator[](const int index)
        {
            return *(m_ptr + index);
        }

        inline ptr_type operator->()
        {
            return m_ptr;
        }

        inline ref_type operator*()
        {
            return *m_ptr;
        }

        inline bool operator==(const DyArrayIterator& it) const
        {
            return m_ptr == it.m_ptr;
        }

        inline bool operator!=(const DyArrayIterator& it) const
        {
            return m_ptr != it.m_ptr;
        }

      private:
        ptr_type m_ptr;
    };

    template <typename T>
    class DyArray
    {
      public:
        using value_type = T;
        using Iterator = DyArrayIterator<DyArray<T>>;

      public:
        DyArray();
        DyArray(const DyArray& array);
        DyArray(DyArray&& array);
        DyArray(const std::initializer_list<T> list);
        DyArray(const T& element);
        ~DyArray();

        DyArray& operator=(const DyArray& array);
        DyArray& operator=(DyArray&& array);
        DyArray& operator=(const std::initializer_list<T> list);
        DyArray& operator=(const T& element);
        DyArray& operator=(T&& element);

        DyArray& operator+=(const DyArray& array);
        DyArray& operator+=(DyArray&& array);
        DyArray& operator+=(const std::initializer_list<T> list);
        DyArray& operator+=(const T& element);

        T& operator[](int index);
        T& operator[](int index) const;

      public:
        inline T* get_data()
        {
            return m_data;
        }

        inline T& get_data() const
        {
            return m_data;
        }

        inline int size() const
        {
            return m_size;
        }

        inline Iterator begin()
        {
            return Iterator(m_data);
        }

        inline Iterator end()
        {
            return Iterator(m_data + m_size);
        }

        inline const Iterator begin() const
        {
            return Iterator(m_data);
        }

        inline const Iterator end() const
        {
            return Iterator(m_data + m_size);
        }

        T& push_back(const T& element);
        void push_back(const DyArray& array);
        void push_back(const std::initializer_list<T> list);

        T& emplace_back(T&& element);

        void clear();
        void resize(int size);

      private:
        T* m_data;
        int m_size;
    };

    template <typename T>
    DyArray<T>::DyArray() : m_data(nullptr), m_size(0)
    {
    }

    template <typename T>
    DyArray<T>::DyArray(const DyArray& array) : m_data(nullptr), m_size(array.m_size)
    {
        if (array.m_data != nullptr)
        {
            m_data = new T[m_size];
            mem_copy(m_data, array.m_data, m_size);
        }
    }

    template <typename T>
    DyArray<T>::DyArray(DyArray&& array) : m_data(static_cast<T*&&>(array.m_data)), m_size(array.m_size)
    {
        array.m_data = nullptr;
        array.m_size = 0;
    }

    template <typename T>
    DyArray<T>::DyArray(const std::initializer_list<T> list) : m_data(nullptr), m_size(list.size())
    {
        if (m_size > 0)
        {
            m_data = new T[m_size];

            int i = 0;
            for (T element : list)
            {
                m_data[i] = element;
                i++;
            }
        }
    }

    template <typename T>
    DyArray<T>::DyArray(const T& element) : m_data(new T[1]), m_size(1)
    {
        m_data[0] = element;
    }

    template <typename T>
    DyArray<T>::~DyArray()
    {
        clear();
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(const DyArray& array)
    {
        clear();

        m_size = array.m_size;
        m_data = new T[m_size];

        mem_copy(m_data, array.m_data, m_size);

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(DyArray&& array)
    {
        clear();

        if (array.m_data != nullptr)
        {
            m_data = static_cast<T*&&>(array.m_data);
            m_size = array.m_size;

            array.m_data = nullptr;
            array.m_size = 0;
        }

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(const std::initializer_list<T> list)
    {
        clear();

        m_size = list.size();

        if (m_size > 0)
        {
            m_data = new T[m_size];

            int i = 0;
            for (T element : list)
            {
                m_data[i] = element;
                i++;
            }
        }

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(const T& element)
    {
        clear();

        m_size = 1;
        m_data = new T[1];

        m_data[0] = element;

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(T&& element)
    {
        clear();

        m_size = 1;
        m_data = new T[1];

        m_data[0] = static_cast<T*&&>(element);
        element = nullptr;

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(const DyArray& array)
    {
        int old_size = m_size;
        resize(m_size + array.m_size);

        int j = 0;
        for (int i = old_size; i < m_size; i++)
        {
            m_data[i] = array.m_data[j];
            j++;
        }

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(DyArray&& array)
    {
        if (array.m_data == nullptr)
            return *this;

        int old_size = m_size;
        m_size += array.m_size;

        m_data = mem_resize(m_data, old_size, m_size);

        int j = old_size;
        for (int i = 0; i < array.m_size; i++)
        {
            m_data[j] = array.m_data[i];
            j++;
        }

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(const std::initializer_list<T> list)
    {
        if (list.size() < 1)
            return *this;

        int old_size = m_size;
        m_size += list.size();

        m_data = mem_resize(m_data, old_size, m_size);

        int i = old_size;
        for (T element : list)
        {
            m_data[i] = element;
            i++;
        }

        return *this;
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(const T& element)
    {
        int old_size = m_size;
        m_size++;

        m_data = mem_resize(m_data, old_size, m_size);
        m_data[old_size] = element;

        return *this;
    }

    template <typename T>
    T& DyArray<T>::operator[](int index)
    {
        return m_data[index];
    }

    template <typename T>
    T& DyArray<T>::operator[](int index) const
    {
        return m_data[index];
    }

    template <typename T>
    T& DyArray<T>::push_back(const T& element)
    {
        int old_size = m_size;
        resize(m_size + 1);

        m_data[old_size] = element;

        return m_data[old_size];
    }

    template <typename T>
    void DyArray<T>::push_back(const std::initializer_list<T> list)
    {
        int old_size = m_size;
        resize(m_size + list.size());

        int i = old_size;
        for (T element : list)
        {
            m_data[i] = element;
            i++;
        }
    }

    template <typename T>
    T& DyArray<T>::emplace_back(T&& element)
    {
        int old_size = m_size;
        m_size += 1;

        m_data = mem_resize(m_data, old_size, m_size);
        m_data[old_size] = static_cast<T&&>(element);

        return m_data[old_size];
    }

    template <typename T>
    void DyArray<T>::clear()
    {
        if (m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
            m_size = 0;
        }
    }

    template <typename T>
    void DyArray<T>::resize(int size)
    {
        int old_size = m_size;
        m_size = size;
        m_data = mem_resize(m_data, old_size, m_size);
    }

} // namespace safire

#endif // SAFIRE_DYNAMIC_ARRAY_HPP
