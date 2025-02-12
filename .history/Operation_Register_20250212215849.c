#include <stdio.h>

#define CALCULATE_LEN(a) (sizeof(a) * 8)

void print_binary(char a, int n)
{
    printf(": ");
    while(n--)
    {
        printf("%d ", (a >> n) & 0x01);
    }
    printf(": %d\n", a);
}

void main()
{
    char a = 0x80;

    for(int i = 0; i < 9; i++)
    {
        printf("a =  0x%x, right shift %d times", a & 0xFF, i);
        print_binary((a >> i), CALCULATE_LEN(a));
    }
}
