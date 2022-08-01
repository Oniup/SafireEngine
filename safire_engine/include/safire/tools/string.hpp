#ifndef SAFIRE_STRING_HPP
#define SAFIRE_STRING_HPP

namespace safire
{

    class String
    {
      public:
        String();
        String(const String& string);
        String(const char* string);
        ~String();

        String& operator=(const String& string);
        String& operator=(String&& string);
        String& operator=(const char* string);

        bool operator==(const String& string) const;
        bool operator==(const char* string) const;
        bool operator!=(const String& string) const;
        bool operator!=(const char* string) const;

        String& operator+=(const String& string);
        String& operator+=(String&& string);
        String& operator+=(const char* string);
        String operator+(const String& string) const;
        String operator+(const char* string) const;

      public:
        inline const char* c_string() const
        {
            return m_string;
        }

        int length() const;

        void append(const String& string);
        void append(const char* string);

        void copy(const String& string);
        void copy(const char* string);
        void move(String&& string);

        void clear();

      private:
        char* m_string;
    };

} // namespace safire

#endif // SAFIRE_STRING_HPP
