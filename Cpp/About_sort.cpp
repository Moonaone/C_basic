#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values = {3, 5, 1, 4, 2};
    // std::sort(values.begin(), values.end());
    // std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(values.begin(), values.end(), [](int a, int b)
    {
        if(a == 1)
        {
            return false;
        }
        if(b == 1)
        {
            return false;
        }

        return a < b;
    });

    for(int value : values)
    {
        std::cout << value << std::endl;
    }

    std::cin.get();
}
