#include <iostream>
#include <string>

int main()
{
    int example[5];
    example[0] = 2;
    example[4] = 4;

    std::cout << example[0] << std::endl;
    std::cout << example << std::endl;

    for(int i = 0; i < 5; i++)
    {
        example[i] = 2;
    }

    example[2] = 5;
    int* ptr = example;
    *(ptr + 2) = 3;

    std::cout << example[2] << std::endl;

    std::cin.get();
}
