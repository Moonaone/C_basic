#include <iostream>
#include <vector>

void HelloWorld(int a)
{
    std::cout << "Hello World" << a << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value:" << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for(int value : values)
        func(value);
}

int main()
{
    typedef void(*HelloWorldFunction)(int);

    HelloWorldFunction function = HelloWorld;

    function(8);

    std::vector<int> values = {1, 5, 4, 2, 3};

    ForEach(values, PrintValue);


    std::cin.get();
}
