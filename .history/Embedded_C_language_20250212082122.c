#include <stdio.h>

// #define LOG_INFO(x) printf("%s is %d\n", #x, (x));
// #define DAY_DELARE(x) int day##x
// #define ADD(x, y) do{(x = (x) + (y));(x++);} while(0)

int main(void)
{
    int a = 10;
    // DAY_DELARE(1) = 100;
    // DAY_DELARE(22) = 200;
    // LOG_INFO(DAY(1));
    // LOG_INFO(DAY(22));

    // if(0)
    //     ADD(a, 10);
    // else
    //     ADD(a, 100);

    printf("a is %d\n", a);
    
    return 0;
}
