#include <iostream>
#include <string>
#include <array>

int main()
{
    const char* name = "Cherno";
    char name2[6] = {'C', 'h', 'e', 'r', 'n', 'o'};
    char name3[7] = {'C', 'h', 'e', 'r', 'n', 'o', '\0'};
    std::string name4 = "Cherno";

    // �ַ����ĵ���
    name4 += "Hello!";
    std::string name5 = std::string("Cherno") + "Hello!";

    std::cout << name << std::endl;
    std::cout << name2 << std::endl;
    std::cout << name3 << std::endl;
    std::cout << name4 << std::endl;
    std::cout << name5 << std::endl;

//    name[2] = 'a';

    std::cin.get();
}

