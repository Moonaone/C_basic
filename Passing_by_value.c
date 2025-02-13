#include <stdio.h>

unsigned long addr = 0;

void show(void)
{
    int a = 10086;
    int b = 10010;

    asm volatile("movl %rbp, addr(%rip)"); // 对寄存器进行操作，用来获取栈帧的地址
}

void main(void)
{
    show();

    int *p = (int *)addr;

    printf("a = %d, b = %d\n", p[-2], p[-1]);
}
