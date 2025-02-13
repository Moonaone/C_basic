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

    return 0;
}

void main(void)
{
    int ret;
    int ret2;

    func(&ret, &ret2);
    printf("ret = %d, ret2 = %d\n", ret, ret2);
}

