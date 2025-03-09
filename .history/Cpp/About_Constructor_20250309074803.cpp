#include <iostream>

class Entity
{
    public:
    float X, Y;

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};


int main()
{
    Entity e;
    e.Print();

    std::cin.get();
}
