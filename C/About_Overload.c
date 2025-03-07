#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void va_func(强制参数， 可变参数)
/*
    1.强制参数至少有一个，代表一种规则，由函数定义者自行定义和解析
    2.可变参数可以有多个，函数定义者和调用者自行决定

    va_list:一个元素的结构体数组
    ----/usr/lib/gcc/x86_64-linux-gnu/9/include----
    typedef __builtin_va_list va_list;
    typedef __gnuc_va_list va_list; // 一个元素的结构体数组

    va_list = struct __va_list_tag
    {
        unsigned int gp_offset;
        unsigned int fp_offset;
        void *overflow_arg_area;
        void *reg_save_area;
    }[1]

    va_start:定位到可变参数的地址
    va_arg:遍历可变参数
    va_end:结束va_list遍历

    #define va_start(v, 1) __builtin_va_start(v, 1)
    #define va_end(v) __builtin_va_end(v)
    #define va_arg(v, 1) __builtin_va_arg(v, 1)
*/

#include <stdarg.h>

// 这里约定n未后面参数的个数(一种规则)
static void va_func(int n, ...)
{
    va_list ptr;
    va_start(ptr, n);
    while(n--)
    {
        printf("%d \n", va_arg(ptr, int));
    }
    va_end(ptr);
}

int main()
{
    va_func(1, 100);
    va_func(2, 200, 300);

    return 0;
}
