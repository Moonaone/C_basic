#include <stdio.h>

/*
    栈是一种只能在一端进行插入和删除操作的线性表，表中允许进行插入和删除操作的一端称为栈顶，另一端称为栈底。
    栈顶的当前位置是动态变化的，栈中元素的个数是变化的，栈顶当前位置由一个称为栈顶指针的位置指示器指示。
    当栈中没有元素时称为空栈。栈的插入操作称为进栈或入栈，栈的删除操作称为出栈或退栈。

    栈的主要特点是后进先出，即后进栈的元素先出栈。栈的插入操作和删除操作都在栈顶进行。
*/

typedef int ElemType;

#define MaxSize 100

typedef struct
{
    ElemType data[MaxSize];
    int top; // 栈顶指针
}SqStack; // 顺序栈

/**
 * @brief 初始化栈
 * 
 * @param s 指向栈的指针的指针
 */
void InitStack(SqStack **s)
{
    *s = (SqStack *)malloc(sizeof(SqStack));
    (*s)->top = -1;
}

/**
 * @brief 销毁栈
 *
 * @param s 指向栈的指针的指针
 */
void DestroyStack(SqStack **s)
{
    free(*s);
}

/**
 * @brief 获取栈的长度
 * 
 * @param s 指向栈的指针
 * @return int 返回栈的长度
 */
int StackLength(SqStack *s)
{
    return (s->top + 1);
}

/**
 * @brief 判断栈是否为空
 *
 * @param s 指向栈的指针
 * @return int 栈为空返回1，否则返回0
 */
int StackEmpty(SqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

/**
 * @brief 向栈中插入元素
 * 
 * @param s 指向栈的指针
 * @param e 要插入的元素
 * @return int 插入成功返回1，否则返回0
 */
int Push(SqStack *s, ElemType e)
{
    if (s->top == MaxSize - 1) // 栈满
        return 0;
    s->top++;
    s->data[s->top] = e;
    return 1;
}

/**
 * @brief 从栈中弹出元素
 * 
 * @param s 指向栈的指针的指针
 * @param e 指向要弹出元素的指针
 * @return int 弹出成功返回1，否则返回0
 */
int Pop(SqStack **s, ElemType *e)
{
    if ((*s)->top == -1) // 栈空
        return 0;
    e = (*s)->data[(*s)->top];
    (*s)->top--;
    return 1; 
}
