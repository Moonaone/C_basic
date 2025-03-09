#include <iostream>
#include <string>

class Entity
{
    private:
    int m_X, m_Y;
    mutable int var; // mutable ���Ըı� const ��Ա������ֵ

    public:
    int GetX() const
    {
        var = 10;
        return m_X;
    }
    void SetX(int x)
    {
        m_X = x;
    }
};

void PrintEntity(const Entity& e)
{
    std::cout << e.GetX() << std::endl;
}

int main()
{
    const int MAX_AGE = 90;

    // const �� * ���: ���ܸı�ָ����ָ�������
    // const �� * �ұ�: ���ܸı�ָ�뱾����ַ��

    int * a = new int;
    *a = 10;
    std::cout << *a << std::endl;
    a = (int*)&MAX_AGE;
    std::cout << *a << std::endl;

    delete a;

    std::cin.get();
}

