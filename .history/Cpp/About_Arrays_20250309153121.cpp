#include <iostream>
#include <string>

int main()
{
    int example[5];
    example[0] = 2;
    example[4] = 4;

    std::cout << example[0] << std::endl;
    std::cout << example << std::endl;

    std::cin.get();
}
