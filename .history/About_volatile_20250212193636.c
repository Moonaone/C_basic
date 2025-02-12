#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
    volatile �ؼ���
        1. ��ֹ�������Ż�����
        2. ��֤�˲�ͬ�̶߳�����������в���ʱ�Ŀɼ��ԣ���һ���߳��޸���ĳ��������ֵ�������ֵ�������߳���˵�������ɼ��ġ�
        3. ��ֹ����ָ��������
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
