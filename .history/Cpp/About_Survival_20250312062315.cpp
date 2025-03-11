#include <iostream>
#include <cstring>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

};

// int* CreateArray()
// {
//     int array[50];
//     return array;
// }

class ScopedPtr
{
private:
    Entity* m_Ptr;

public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
    {

    }

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main()
{
    {
        Entity e;
        // Entity* e = new Entity();
    }

    std::cin.get();
}
