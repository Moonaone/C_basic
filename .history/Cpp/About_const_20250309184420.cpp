#include <iostream>
#include <string>

int main()
{
    const int MAX_AGE = 90;

    int * a = new int;
    *a = 10;
    std::cout << *a << std::endl;
    a = (int*)&MAX_AGE;
    std::cout << *a << std::endl;

    delete a;

    std::cin.get();
}

