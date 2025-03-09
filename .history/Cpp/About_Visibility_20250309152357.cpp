#include <iostream>
#include <string>

class Entity
{
    private:
    int X, Y;

    public:
    Entity()
    {
        X = 0;
    }
};

class Player : public Entity
{
    public:
    Player()
    {
        
    }
};

int main()
{


    std::cin.get();
}

/*
    public: 大家都可以用
    private: 只有自己和友元可以用
    protected: 只有自己和友元和子类可以用
*/
