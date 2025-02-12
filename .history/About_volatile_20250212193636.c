#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
    volatile 关键字
        1. 防止编译器优化代码
        2. 保证了不同线程对这个变量进行操作时的可见性，即一个线程修改了某个变量的值，这个新值对其他线程来说是立即可见的。
        3. 禁止进行指令重排序。
*/

int wait = 1;

void* function(void* arg)
{
    while(1)
    {
        sleep(1);
        wait = 0;
        printf("wait = %d in thread\n", wait);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, function, NULL);

    while(wait);
    printf("wait = %d in main\n", wait);

    return 0;
}
