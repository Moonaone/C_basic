#include <stdio.h>

int a = 10;
int b;

int func(void)
{
    static int d = 10;
    b++;
    return (++d);
}

int main(void)
{
    static int c;
    printf("%p %p %p", &a, &b, &c);

    a = 20;
    b = 30;
    c = 40;

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    printf("b = %d, d = %d, d = %d\n", b, func(), func());

    return 0;
}

