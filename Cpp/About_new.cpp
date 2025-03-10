#include <iostream>
#include <cstring>
#include <new>

using String = std::string;

class Entity
{
    private:
    String m_Name;

    public:
    Entity() : m_Name("Unknown")
    {
        
    }
    Entity(const String& name) : m_Name(name)
    {

    }

    const String& GetName() const
    {
        return m_Name;
    }
    
};

int main()
{
    int a = 2;
    int* b = new int[50];

    Entity* e = new Entity(); // 调用默认构造函数
    Entity* e2 = (Entity*)malloc(sizeof(Entity)); // 仅分配内存

    delete e;
    delete[] b;
    free(e2);

    std::cin.get();
}
