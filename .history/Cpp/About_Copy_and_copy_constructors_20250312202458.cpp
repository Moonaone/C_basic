#include <iostream>
#include <cstring>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size + 1); 
        m_Buffer[m_Size] = 0;
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{   
    String string = "Cherno";
    String second = string;

    std::cout << string << std::endl;
    std::cout << second << std::endl;

    std::cin.get();
}

