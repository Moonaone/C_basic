#include <iostream>
#include <string>

class Entity
{
    private:
    int m_X, m_Y;
    mutable int var; // mutable 可以改变 const 成员变量的值

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

    // const 在 * 左边: 不能改变指针所指向的内容
    // const 在 * 右边: 不能改变指针本身（地址）

    int * a = new int;
    *a = 10;
    std::cout << *a << std::endl;
    a = (int*)&MAX_AGE;
    std::cout << *a << std::endl;

    delete a;

    std::cin.get();
}

