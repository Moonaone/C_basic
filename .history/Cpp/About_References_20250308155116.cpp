#include <iostream>

# define LOG(x) std::cout << x << std::endl;

int main()
{
    int a = 5;
    int& ref = a;

    ref = 2;

    LOG(a);

    std::cin.get();
}

