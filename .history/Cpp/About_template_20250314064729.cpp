#include <iostream>
#include <cstring>

// template<typename T>
// void Print(T value)
// {
//     std::cout << value << std::endl;
// }

template<typename T, int N>
class Array
{
private:
    T m_array[N];

public:
    int GetSize() const
    {
        return n;
    }
};

int main()
{
    // Print(1);
    // Print(1.1f);
    // Print("Hello");
    Array<int, 5> array;
    std::cout << array.GetSize() << std::endl;

    std::cin.get();
}
