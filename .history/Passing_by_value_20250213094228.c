#include <stdio.h>

unsigned long addr = 0;

void show(void)
{
    int a = 10086;
    int b = 10010;

    asm volatile("movl %rbp, addr(%rip)"); // �ԼĴ������в�����������ȡջ֡�ĵ�ַ
}

void main(void)
{
    show();

    int *p = (int *)addr;

    printf("a = %d, b = %d\n", p[-2], p[-1]);
}
