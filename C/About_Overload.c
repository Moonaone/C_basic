#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void va_func(ǿ�Ʋ����� �ɱ����)
/*
    1.ǿ�Ʋ���������һ��������һ�ֹ����ɺ������������ж���ͽ���
    2.�ɱ���������ж�������������ߺ͵��������о���

    va_list:һ��Ԫ�صĽṹ������
    ----/usr/lib/gcc/x86_64-linux-gnu/9/include----
    typedef __builtin_va_list va_list;
    typedef __gnuc_va_list va_list; // һ��Ԫ�صĽṹ������

    va_list = struct __va_list_tag
    {
        unsigned int gp_offset;
        unsigned int fp_offset;
        void *overflow_arg_area;
        void *reg_save_area;
    }[1]

    va_start:��λ���ɱ�����ĵ�ַ
    va_arg:�����ɱ����
    va_end:����va_list����

    #define va_start(v, 1) __builtin_va_start(v, 1)
    #define va_end(v) __builtin_va_end(v)
    #define va_arg(v, 1) __builtin_va_arg(v, 1)
*/

#include <stdarg.h>

// ����Լ��nδ��������ĸ���(һ�ֹ���)
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
