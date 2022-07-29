#include "safire/tools/string.hpp"

#include "safire/tools/memory.hpp"

#include <stdio.h>
#include <string.h>

namespace safire
{

    String::String() : m_string(nullptr)
    {
    }

    String::String(const String& string) : String(string.m_string)
    {
    }

    String::String(const char* string) : m_string(nullptr)
    {
        int length = strlen(string);

        m_string = new char[length];
        mem_copy(m_string, string, length);
        m_string[length] = '\0';
    }

    String::~String()
    {
        clear();
    }

    String& String::operator=(const String& string)
    {
        return *this = string.m_string;
    }

    String& String::operator=(String&& string)
    {
        move(static_cast<String&&>(string));

        return *this;
    }

    String& String::operator=(const char* string)
    {

        return *this;
    }

    bool String::operator==(const String& string) const
    {
        return *this == string.m_string;
    }

    bool String::operator==(const char* string) const
    {
        int length = strlen(m_string);

        return strncmp(m_string, string, length) == 0;
    }

    bool String::operator!=(const String& string) const
    {
        return !(*this == string.m_string);
    }

    bool String::operator!=(const char* string) const
    {
        return !(*this == string);
    }

    String& String::operator+=(const String& string)
    {
        *this += string.m_string;
        return *this;
    }

    String& String::operator+=(String&& string)
    {
        move(static_cast<String&&>(string));

        return *this;
    }

    String& String::operator+=(const char* string)
    {
        String result = *this;
        result.append(string);

        return *this;
    }

    String String::operator+(const String& string) const
    {
        return *this + string.m_string;
    }

    String String::operator+(const char* string) const
    {
        String result = *this;
        result.append(string);

        return result;
    }

    int String::get_length() const
    {
        return strlen(m_string);
    }

    void String::append(const String& string)
    {
        append(string.m_string);
    }

    void String::append(const char* string)
    {
        int old_length = strlen(m_string);
        int length = old_length + strlen(string);

        m_string = mem_resize(m_string, old_length, length);
        mem_copy(m_string, string, length, old_length);
        m_string[length] = '\0';
    }

    void String::copy(const String& string)
    {
        copy(string.m_string);
    }

    void String::copy(const char* string)
    {
        int length = strlen(string);

        m_string = new char[length];
        mem_copy(m_string, string, length);
        m_string[length] = '\0';
    }

    void String::move(String&& string)
    {
        clear();
        if (string.m_string == nullptr)
            return;

        m_string = static_cast<char*>(string.m_string);
        string.m_string = nullptr;
    }

    void String::clear()
    {
        if (m_string != nullptr)
        {
            delete[] m_string;
            m_string = nullptr;
        }
    }

} // namespace safire
