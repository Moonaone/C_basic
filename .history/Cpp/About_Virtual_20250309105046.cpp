#include <iostream>
#include <string>

class Entity
{
    public:
    virtual std::string GetName()
    {
        return "Entity";
    }
};

class Player : public Entity
{
    private:
    std::string m_Name;

    public:
    Player(const std::string& name)
        : m_Name(name){}

    std::string GetName()
    {
        return m_Name;
    }
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    // std::cout << e->GetName() << std::endl;
    PrintName(e);

    Player* p = new Player("Cherno");
    // std::cout << p->GetName() << std::endl; 
    PrintName(p);

    Entity* entity = p;
    // std::cout << entity->GetName() << std::endl;

    std::cin.get();
}
