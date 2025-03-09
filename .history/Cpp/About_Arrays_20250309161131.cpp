#include <iostream>
#include <string>
#include <array>

class Entity
{
    public:
    static const int exampleSize = 5;
    int example[exampleSize];

    std::array<int, 5> another;

    

    Entity()
    {
        for(int i = 0; i < exampleSize; i++)
        {
            example[i] = 2;
        }
        for(int i = 0; i < another.size(); i++)
        {
            another[i] = 2;
        }
    }
    
};

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
    *(int*)((char*)ptr + 8) = 6;

    std::cout << example[2] << std::endl;

    std::cin.get();
}
