/*
    Fibonacci为1200年代的欧洲数学家，在他的着作中曾经提到：「若有一只免子每个月生一只小免
    子，一个月后小免子也开始生产。起初只有一只免子，一个月后就有两只免子，二个月后有三
    只免子，三个月后有五只免子（小免子投入生产）......。
    如果不太理解这个例子的话，举个图就知道了，注意新生的小免子需一个月成长期才会投入生
    产，类似的道理也可以用于植物的生长，这就是Fibonacci数列，一般习惯称之为费氏数列，例
    如以下： 1、1 、2、3、5、8、13、21、34、55、89......
*/

#include <stdio.h>

int Fibonacci(int Fib[], int n)
{
    if(n == 1)
    {
        Fib[0] = 1;
    }
    if(n == 2)
    {
        Fib[1] = 1;        
    }
    if(n > 2)
    {
        Fib[n - 1] = Fibonacci(Fib, n - 1) + Fibonacci(Fib, n - 2);
    }

    return Fib[n - 1];
}

int main()
{
    int Fib[100] = {0};
    int n = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        Fib[i] = Fibonacci(Fib, i + 1);
        printf("%d ", Fib[i]);
    }

    return 0;
}