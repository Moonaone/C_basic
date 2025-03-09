#include <iostream>
#include <string>
#include <array>

int main()
{
    char* name = "Cherno";
    char name2[6] = {'C', 'h', 'e', 'r', 'n', 'o'};

    std::cout << name << std::endl;
    std::cout << name2 << std::endl;

    name[2] = 'a';

    std::cin.get();
}

