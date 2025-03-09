#include <iostream>

class Entity
{
    public:
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
    }

    // void Init()
    // {
    //     X = 0.0f;
    //     Y = 0.0f;
    // }

    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};


int main()
{
    Entity e;
    // e.Init();
    e.Print();

    Entity e1(10.0f, 5.0f);
    e1.Print();

    std::cin.get();
}
