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
    public: ��Ҷ�������
    private: ֻ���Լ�����Ԫ������
    protected: ֻ���Լ�����Ԫ�����������
*/
