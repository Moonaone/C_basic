#include <iostream>

struct Entity
{
    /* data */
    // int x, y;
    static int x, y;

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

// static void Print(Entity e)
// {
//     std::cout << e.x << ", " << e.y << std::endl;
// }


int main()
{
    Entity e;
    // e.x = 2;
    // e.y = 3;
    Entity::x = 2;
    Entity::y = 3;

    // Entity e1 = {5, 8};
    Entity e1;
    // e1.x = 5;
    // e1.y = 8;
    Entity::x = 5;
    Entity::y = 8;

    e.Print();
    e1.Print();

    std::cin.get();
}
