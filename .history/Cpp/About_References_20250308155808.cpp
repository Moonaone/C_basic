#include <iostream>

# define LOG(x) std::cout << x << std::endl;

void Increment(int value)
{
    value++;
}

void Increment1(int * value)
{
    (*value)++;
}

int main()
{
    int a = 5;
    int& ref = a;

    ref = 2;

    LOG(a);

    Increment(a);
    LOG(a);

    Increment1(&a);
    LOG(a);

    std::cin.get();
}

