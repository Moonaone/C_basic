#include <iostream>
#include <vector>

void HelloWorld(int a)
{
    std::cout << "Hello World" << a << std::endl;
}

void ForEach(const std::vector<int>& values)
{
    
}

int main()
{
    typedef void(*HelloWorldFunction)(int);

    HelloWorldFunction function = HelloWorld;

    function(8);

    std::vector<int> values = {1, 5, 4, 2, 3};




    std::cin.get();
}
