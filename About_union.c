#include <stdio.h>

union abc
{
    int a;
    char b;
    double c;
};

int main(void)
{
    union abc d;
    d.a = 1;
    printf("d.a = %d d.b = %d\n", d.a, d.b);
    d.b = 100;
    printf("d.a = %d d.b = %d\n", d.a, d.b);

    return 0;
}
