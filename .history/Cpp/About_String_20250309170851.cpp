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

//    name[2] = 'a';

    std::cin.get();
}

