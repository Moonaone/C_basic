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

// Ϊ�˱���������ͻ�����Ǿ�����ʹ�������ռ�
using namespace apple;
using namespace orange;

int main()
{
    print("Hello!");

    std::cin.get();
}
