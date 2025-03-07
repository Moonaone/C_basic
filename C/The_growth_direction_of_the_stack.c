#include <stdio.h>
#include <stdlib.h>

void func(void)
{
    int *p1 = (int *)malloc(sizeof(int));
    int *p2 = (int *)malloc(sizeof(int));
    if(p2 > p1)
    {
        printf("heap upward \n");
    }
    else
    {
        printf("heap downward \n");
    }
    free(p1);
    free(p2);

    int a = 1;
    int b = 2;
    if(&b > &a)
    {
        printf("stack upward \n");
    }
    else
    {
        printf("stack downward \n");
    }
}

int main()
{
    func();
    return 0;
}
