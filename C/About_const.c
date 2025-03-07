#include <stdio.h>

const int *a; // const *a 靠近*，所以地址指向的内容(*a)不能改变
int const *b; // int const *b 靠近*，所以地址指向的内容(*b)不能改变
int * const c; // int * const c 靠近c，所以c指针变量不能改变
const int * const d; // const int * const d 靠近*，所以地址指向的内容(*d)不能改变，靠近d，所以d指针变量不能改变

const int NUMBER = 5; // 

int main()
{
    // 下面五个语句编译会报错
    *a = 1;
    *b = 1;
    c = 1;
    *d = 1;
    d = 1;

    int a = NUMBER; // 直接赋值，执行效率高

    return 0;
}

