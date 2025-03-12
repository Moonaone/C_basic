#include <iostream>
#include <cstring>

class Entity
{
public:
    int x;

public:
    void Print() const
    {
        std::cout << "Hello" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity* m_Obj;

public:
    ScopedPtr(Entity* obj)
        : m_Obj(obj)
        {

        }
    
    ~ScopedPtr()
    {
        delete m_Obj;
    }

    // Entity* GetObject()
    // {
    //     return m_Obj;
    // }

    Entity* operator->()
    {
        return m_Obj;
    }

    const Entity* operator->() const 
    {
        return m_Obj;
    }
};

int main()
{
    Entity e;
    e.Print();

    Entity* ptr = &e;
    Entity& entity = *ptr;
    entity.Print();

    (*ptr).Print();
    ptr->Print(); // 相当于上面的 (*ptr).Print();  逆引用
    ptr->x = 2;

    ScopedPtr entity = new Entity();
    entity->Print();

    std::cin.get();
}
