#include <stdio.h>

/*
    ջ��һ��ֻ����һ�˽��в����ɾ�����������Ա�����������в����ɾ��������һ�˳�Ϊջ������һ�˳�Ϊջ�ס�
    ջ���ĵ�ǰλ���Ƕ�̬�仯�ģ�ջ��Ԫ�صĸ����Ǳ仯�ģ�ջ����ǰλ����һ����Ϊջ��ָ���λ��ָʾ��ָʾ��
    ��ջ��û��Ԫ��ʱ��Ϊ��ջ��ջ�Ĳ��������Ϊ��ջ����ջ��ջ��ɾ��������Ϊ��ջ����ջ��

    ջ����Ҫ�ص��Ǻ���ȳ��������ջ��Ԫ���ȳ�ջ��ջ�Ĳ��������ɾ����������ջ�����С�
*/

typedef int ElemType;

#define MaxSize 100

typedef struct
{
    ElemType data[MaxSize];
    int top; // ջ��ָ��
}SqStack; // ˳��ջ

/**
 * @brief ��ʼ��ջ
 * 
 * @param s ָ��ջ��ָ���ָ��
 */
void InitStack(SqStack **s)
{
    *s = (SqStack *)malloc(sizeof(SqStack));
    (*s)->top = -1;
}

/**
 * @brief ����ջ
 *
 * @param s ָ��ջ��ָ���ָ��
 */
void DestroyStack(SqStack **s)
{
    free(*s);
}

/**
 * @brief ��ȡջ�ĳ���
 * 
 * @param s ָ��ջ��ָ��
 * @return int ����ջ�ĳ���
 */
int StackLength(SqStack *s)
{
    return (s->top + 1);
}

/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 *
 * @param s ָ��ջ��ָ��
 * @return int ջΪ�շ���1�����򷵻�0
 */
int StackEmpty(SqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

/**
 * @brief ��ջ�в���Ԫ��
 * 
 * @param s ָ��ջ��ָ��
 * @param e Ҫ�����Ԫ��
 * @return int ����ɹ�����1�����򷵻�0
 */
int Push(SqStack *s, ElemType e)
{
    if (s->top == MaxSize - 1) // ջ��
        return 0;
    s->top++;
    s->data[s->top] = e;
    return 1;
}

/**
 * @brief ��ջ�е���Ԫ��
 * 
 * @param s ָ��ջ��ָ���ָ��
 * @param e ָ��Ҫ����Ԫ�ص�ָ��
 * @return int �����ɹ�����1�����򷵻�0
 */
int Pop(SqStack **s, ElemType *e)
{
    if ((*s)->top == -1) // ջ��
        return 0;
    e = (*s)->data[(*s)->top];
    (*s)->top--;
    return 1; 
}
