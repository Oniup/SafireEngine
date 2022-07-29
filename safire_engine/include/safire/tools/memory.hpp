#ifndef SAFIRE_MEMORY_HPP
#define SAFIRE_MEMORY_HPP

#include <assert.h>
#include <stdio.h>

#define SAFIRE_ASSERT(X, M) assert(X && "[SAFIRE ENGINE FAILTAL ERROR]:" && M)

namespace safire
{

    template <typename T>
    T* mem_resize(T* data, int current, int new_size);
    template <typename T>
    T* mem_copy(T* dest, const T* src, int size, int offset = 0);
    template <typename T>
    T* mem_fill(T* dest, const T& fill, int size, int offset = 0);

    template <typename T>
    T* mem_resize(T* data, int current, int new_size)
    {
        if (data == nullptr)
        {
            data = new T[new_size];

            return data;
        }

        T* temp = new T[current];
        mem_copy(temp, data, current);

        delete data;
        data = new T[new_size];
        mem_copy(data, temp, current);

        return data;
    }

    template <typename T>
    T* mem_copy(T* dest, const T* src, int size, int offset)
    {
        SAFIRE_ASSERT(dest, "dest needs to have the memory allocated to it when coping");

        int j = 0;
        for (int i = offset; i < size; i++)
        {
            dest[i] = src[j];
            j++;
        }

        return dest;
    }

    template <typename T>
    T* mem_fill(T* dest, const T& fill, int size, int offset)
    {
        SAFIRE_ASSERT(dest, "dest needs to have memory allocated to it when filling it");

        for (int i = offset; i < size; i++)
            dest[i] = fill;

        return dest;
    }

} // namespace safire

#endif // SAFIRE_MEMORY_HPP
