#include <iostream>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>

namespace apple
{
    void print(const char* text)
    {
        std::cout << text << std::endl;
    }

    void print_again() {}
}

int main()
{
    namespace a = apple;
    a::print("Hello");


    std::cin.get();
}
