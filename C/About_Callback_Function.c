#include <stdio.h>
#include <stdarg.h>

void exchange_int(void *a, void *b)
{
    int *_a = (int *)a;
    int *_b = (int *)b;
    int tmp = 0;

    tmp = *_a;
    *_a = *_b;
    *_b = tmp;
}

void exchange_double(void *a, void *b)
{
    double *_a = (double *)a;
    double *_b = (double *)b;
    double tmp = 0;

    tmp = *_a;
    *_a = *_b;
    *_b = tmp;
}

typedef void (*func)(void *, void *);

void swap(func exchange, void *a, void *b)
{
    exchange(a, b);
}

void main(void)
{
    int a = 10;
    int b = 20;
    double c = 10.5;
    double d = 20.5;

    swap(exchange_int, &a, &b);
    swap(exchange_double, &c, &d);

    printf("a = %d, b = %d\n", a, b);
    printf("c = %lf, d = %lf\n", c, d);
}
