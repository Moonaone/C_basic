#include <iostream>

struct Entity
{
    /* data */
    int x, y;
};


int main()
{
    // int a = 50;
    // // double value = a;
    // double value = *(double*)&a;

    // std::cout << value << std::endl;

    Entity e = {5, 8};
    int* position = (int*)&e;
    int y = *(int*)((char*)&e + 4);
    std::cout << y << std::endl;

    std::cin.get();
}
