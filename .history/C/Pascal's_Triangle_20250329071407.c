/*
    °ÍË¹¿¨Èý½ÇÐÎ
*/

#include <stdio.h>

#define N 12

long combi(int n, int r)
{
    int i;
    long p = 1;
    for(i = 1; i <= r; i++)
    {
        p = p * (n - i  + 1) / i;
    }
    return p;
}

void paint()
{
    int n, r, t;
    for(n = 0; n <= N; n++)
    {
        for(r = 0; r <= n; r++)
        {
            int i;
            if(r == 0)
            {
                for(i = 0;i <= (N - n); i++)
                {
                    printf("    ");
                }
            }
            else
            {
                printf("    ");
            }
            printf("%3d", combi(n, r));
        }
        printf("\n");
    }
}

int main()
{
    paint();

    return 0;
}
