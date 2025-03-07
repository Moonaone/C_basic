#include <stdio.h>

int func(int *a, int *b)
{
    if(!a || !b) // 保证a,b不为空指针
    {
        return -1;
    }
    *a = 100 * 2;
    *b = 200 * 2;

    printf("a = %p, b = %p\n", (void*)a, (void*)b);
    printf("a = %p, b = %p\n", a, b);
    printf("a = %d, b = %d\n", *a, *b);

    return 0;
}

/*
void main(void)
{
    int ret;
    int ret2;

    func(&ret, &ret2);
    printf("ret = %d, ret2 = %d\n", ret, ret2);
}
*/

// 连续空间的传递

struct abc
{
    int a;
    int b;
    int c;
};

int func2(struct abc *p, int b[])
{
    printf("a = %d, b = %d, c = %d\n", p->a, p->b, p->c);
    printf("%d %d,\n", b[0], b[1]);

    return 0;
}

void main(void)
{
    int ret = 0;
    struct abc a = 
    {
        .a = 1,
       .b = 2,
       .c = 3,
    };
    int b[2] = {4, 5};

    ret = func2(&a, b);

    int e = 10;
    int *d = &e;

    printf("d = %d\n", *d);
    printf("d = %p\n", d);
    printf("d = %p\n", &d);
}
