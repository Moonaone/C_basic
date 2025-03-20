#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for(int value : values)
        func(value);
}

int main()
{
    std::vector<int> values = {1, 5, 4, 2, 3};
    // ForEach(values, [](int value){std::cout << "Value: " << value << std::endl;});
    auto lamdba = [](int value){std::cout << "Value: " << value << std::endl;};
    
    ForEach(values, lamdba);

    std::cin.get();
}
