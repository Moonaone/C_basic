#include <iostream>
#include <cstring>
#include <array>
#include <stdlib.h>

void PrintString(const std::string& str)
{
    std::cout << str << std::endl;
}

int main()
{
    const char* name = "Cherno";
    char name2[6] = {'C', 'h', 'e', 'r', 'n', 'o'};
    char name3[7] = {'C', 'h', 'e', 'r', 'n', 'o', '\0'};
    std::string name4 = "Cherno";

    // ×Ö·û´®µÄµþ¼Ó
    name4 += " Hello!";
    std::string name5 = std::string("Cherno") + " Hello!";

    bool contains = name4.find("no") != std::string::npos;

    std::cout << name << std::endl;
    std::cout << name2 << std::endl;
    std::cout << name3 << std::endl;
    std::cout << name4 << std::endl;
    std::cout << name5 << std::endl;

    const char name6[8] = "Che\0rno";
    std::cout << strlen(name6) << std::endl;

    // ¿í×Ö·û
    const wchar_t* name7 = L"Cherno";
    std::cout << name7 << std::endl;

    const char16_t* name8 = u"Cherno";
    const char32_t* name9 = U"Cherno";

//    name[2] = 'a';

    using namespace std::string_literals;
    std::u32string name0 = U"Cherno"s + U"Hello";

    const char* example = R"(Line1
    Line2
    Line3
    Line4)";

    const char* ex = "Line1\n"
    "Line2\n"
    "Line3\n";

    std::cin.get();
}

