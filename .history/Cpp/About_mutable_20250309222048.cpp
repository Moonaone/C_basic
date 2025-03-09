#include <iostream>
class Entity
{
    private:
    std::string m_Name;
    mutable int m_DebugCount = 0;

    public:
    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName();

    int x = 8;
    auto f = [=]() mutable
    {
        x++;
        std::cout << "Hello" << std::endl;
    };

    std::cin.get();
}


