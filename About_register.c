#include <stdio.h>

int main()
{
    register char a = 1;

    printf("a = %d , addr of a:%p\n", a, &a);

    return 0;
}

