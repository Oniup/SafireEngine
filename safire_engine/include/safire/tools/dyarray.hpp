#ifndef SAFIRE_DYNAMIC_ARRAY_HPP
#define SAFIRE_DYNAMIC_ARRAY_HPP

#include "safire/tools/memory.hpp"

#include <initializer_list>

namespace safire
{

    template <typename T>
    class DyArray
    {
      public:
        DyArray();
        ~DyArray();
        DyArray(const DyArray& array);
        DyArray(DyArray&& array);
        DyArray(const std::initializer_list<T> list);
        DyArray(DyArray& array);
        DyArray(const T& element);

        DyArray& operator=(const DyArray& array);
        DyArray& operator=(DyArray&& array);
        DyArray& operator=(const std::initializer_list<T> list);
        DyArray& operator=(DyArray& array);
        DyArray& operator=(const T& element);

        DyArray& operator+=(const DyArray& array);
        DyArray& operator+=(DyArray&& array);
        DyArray& operator+=(const std::initializer_list<T> list);
        DyArray& operator+=(DyArray& array);
        DyArray& operator+=(const T& element);

      public:
        inline int get_length() const
        {
            return m_length;
        }

        inline const T* get_raw() const
        {
            return m_data;
        }

        void push_back(const DyArray& array);
        void push_back(const std::initializer_list<T> list);
        void push_back(DyArray& array);
        void push_back(const T& element);

        void insert(const DyArray& array);
        void insert(const std::initializer_list<T> list);
        void insert(DyArray& array);
        void insert(const T& element);

        void emplace_back(DyArray&& array);
        void emplace_back(T&& element);

        void pop_back(int count = 1);

        void clear();

      private:
        T* m_data;
        int m_length;
    };

    template <typename T>
    DyArray<T>::DyArray() : m_data(nullptr), m_length(0)
    {
    }

    template <typename T>
    DyArray<T>::~DyArray()
    {
        clear();
    }

    template <typename T>
    DyArray<T>::DyArray(const DyArray& array)
    {
        clear();

        m_data = new T[array.m_length];
        mem_copy(m_data, array.m_data, m_length);
    }

    template <typename T>
    DyArray<T>::DyArray(DyArray&& array)
    {
        emplace_back()
    }

    template <typename T>
    DyArray<T>::DyArray(const std::initializer_list<T> list)
    {
    }

    template <typename T>
    DyArray<T>::DyArray(DyArray& array)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(const DyArray& array)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(DyArray&& array)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(const std::initializer_list<T> list)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(DyArray& array)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator=(const T& element)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(const DyArray& array)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(DyArray&& array)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(const std::initializer_list<T> list)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(DyArray& array)
    {
    }

    template <typename T>
    DyArray<T>& DyArray<T>::operator+=(const T& element)
    {
    }

    template <typename T>
    void DyArray<T>::push_back(const DyArray& array)
    {
    }

    template <typename T>
    void DyArray<T>::push_back(const std::initializer_list<T> list)
    {
    }

    template <typename T>
    void DyArray<T>::push_back(DyArray& array)
    {
    }

    template <typename T>
    void DyArray<T>::push_back(const T& element)
    {
    }

    template <typename T>
    void DyArray<T>::insert(const DyArray& array)
    {
    }

    template <typename T>
    void DyArray<T>::insert(const std::initializer_list<T> list)
    {
    }

    template <typename T>
    void DyArray<T>::insert(DyArray& array)
    {
    }

    template <typename T>
    void DyArray<T>::insert(const T& element)
    {
    }

    template <typename T>
    void DyArray<T>::emplace_back(DyArray&& array)
    {
        int old_length = m_length;
        m_length += array.m_length;
        m_data = mem_resize(m_data, old_length, m_length);

        // TODO: need to make a memory function for moving data into another

        array.m_data = nullptr;
        array.m_length = 0;
    }

    template <typename T>
    void DyArray<T>::emplace_back(T&& element)
    {
        int current = m_length;
        m_length += 1;
        m_data = mem_resize(m_data, current, m_length);

        m_data[current] = static_cast<T*&&>(element);
        element = nullptr;
    }

    template <typename T>
    void DyArray<T>::pop_back(int count)
    {
        int old_length = m_length;
        m_length -= count;
        m_data = mem_resize(m_data, old_length, m_length);
    }

    template <typename T>
    void DyArray<T>::clear()
    {
    }

} // namespace safire

#endif // SAFIRE_DYNAMIC_ARRAY_HPP
