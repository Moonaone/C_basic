#include <iostream>
#include <string>

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

