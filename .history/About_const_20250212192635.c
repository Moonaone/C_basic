#include <stdio.h>

const int *a; // const *a ����*�����Ե�ַָ�������(*a)���ܸı�
int const *b; // int const *b ����*�����Ե�ַָ�������(*b)���ܸı�
int * const c; // int * const c ����c������cָ��������ܸı�
const int * const d; // const int * const d ����*�����Ե�ַָ�������(*d)���ܸı䣬����d������dָ��������ܸı�

const int NUMBER = 5; // 

int main()
{
    // �������������ᱨ��
    *a = 1;
    *b = 1;
    c = 1;
    *d = 1;
    d = 1;

    int a = NUMBER; // ֱ�Ӹ�ֵ��ִ��Ч�ʸ�

    return 0;
}

