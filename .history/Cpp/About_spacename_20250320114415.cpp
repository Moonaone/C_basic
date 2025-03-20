#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>

namespace apple
{
    void print(const std::string& text)
    {
        std::cout << text << std::endl;
    }
}

namespace orange
{
    void print(const char* text)
    {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

// 为了避免命名冲突，我们尽量少使用命名空间
using namespace apple;
using namespace orange;

int main()
{
    print("Hello!");

    std::cin.get();
}
