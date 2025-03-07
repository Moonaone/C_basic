#include <stdio.h>

#define MaxSize 50

typedef char ElemType;

typedef struct{
    ElemType data[MaxSize]; // 存放顺序表元素
    int length; // 存放顺序表的长度
}SqList; // 顺序表的类型定义

typedef struct LNode
{
    ElemType data; // 数据域
    struct LNode *next; // 指针域, 指向后继结点
}LinkList; // 单链表的类型定义

typedef struct DNode
{
    ElemType data; // 数据域
    struct DNode *prior; // 指针域, 指向直接前驱结点
    struct DNode *next; // 指针域, 指向直接后继结点
}DLinkList; // 双链表的类型定义

/**
 * @brief 在有序顺序表中插入元素
 * 
 * @param L 指向顺序表的指针的指针
 * @param e 要插入的元素
 * @return int 插入成功返回1，元素已存在返回0
 */
int ListInsert(SqList **L, ElemType e)
{
    int i = 0, j;
    while(i < (*L)->length && (*L)->data[i] < e)
        i++;
    if((*L)->data[i] == e)
    {
        return 0;
    }
    for(j = ListLength(*L); j > i; j--)
    {
        (*L)->data[j] = (*L)->data[j-1];
    }
    (*L)->data[i] = e;
    (*L)->length++;
    return 1;
}

/*
    线性表和有序表的区别在于：
        线性表是无序的，有序表是有序的
*/

/*
    假设有两个有序表LA，LB，设计一个算法，将它们合并成一个有序表LC(假设LA和LB中元素均不相同)，要求不要破坏LA和LB
*/

/**
 * @brief 采用顺序表合并两个有序表
 *
 * @param LA 指向第一个有序表的指针
 * @param LB 指向第二个有序表的指针
 * @param LC 指向合并后的有序表的指针的指针
 */
void UnionList1(SqList *LA, SqList *LB, SqList **LC)
{
    int i = 0, j = 0, k = 0; // i，j，k分别为LA，LB，LC的下标
    *LC = (SqList *)malloc(sizeof(SqList));
    (*LC)->length = 0;
    while(i < LA->length && j < LB->length)
    {
        if(LA->data[i] < LB->data[j])
        {
            (*LC)->data[k] = LA->data[i];
            i++;
            k++;
        }
        else
        {
            (*LC)->data[k] = LB->data[j];
            j++;
            k++;
        }
    }
    while(i < LA->length)
    {
        (*LC)->data[k] = LA->data[i];
        i++;
        k++;
    }
    while(j < LB->length)
    {
        (*LC)->data[k] = LB->data[j];
        j++;
        k++;
    }
    (*LC)->length = k;
}

/**
 * @brief 采用单链表合并两个有序表
 *
 * @param LA 指向第一个有序表的指针
 * @param LB 指向第二个有序表的指针
 * @param LC 指向合并后的有序表的指针的指针
 */
void UnionList2(LinkList *LA, LinkList *LB, LinkList **LC)
{
    LinkList *pa = LA->next, *pb = LB->next, *pc, *s; // pa，pb，pc分别为LA，LB，LC的指针
    (*LC) = (LinkList *)malloc(sizeof(LinkList)); // 创建头结点
    pc = (*LC); // pc始终指向LC的尾结点
    while(pa != NULL && pb!= NULL)
    {
        if(pa->data < pb->data)
        {
            s = (LinkList *)malloc(sizeof(LinkList));
            s->data = pa->data;
            pc->next = s;
            pc = s;
            pa = pa->next;
        }
        else
        {
            s = (LinkList *)malloc(sizeof(LinkList));
            s->data = pb->data;
            pc->next = s;
            pc = s;
            pb = pb->next;
        }
    }
    while(pa!= NULL)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = pa->data;
        pc->next = s;
        pc = s;
        pa = pa->next;
    }
    while(pb!= NULL)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = pb->data;
        pc->next = s;
        pc = s;
        pb = pb->next;
    }
    pc->next = NULL;
}

/*
    已知3个带头结点的单链表LA，LB，LC中的结点均按值非递减有序排列(假设每个单链表不存在数据值相同的结点，但三个单链表中可能存在相同值的结点)，编写一个算法对LA链表进行如下操作：使操作后的链表LA中仅留下3个表中均包含的数据元素的结点，且没有重复数据元素(例如：LA={1,2,3,4,5}，LB={1,2,3,4,5}，LC={1,2,3,4,5}，则操作后的LA={1,2,3,4,5})，并释放LA中所有无用结点，要求算法的时间复杂度为O(n+m+p)，其中n，m，p分别为LA，LB，LC的长度
*/

/**
 * @brief 对LA链表进行操作
 *
 * @param LA 指向第一个有序表的指针
 * @param LB 指向第二个有序表的指针
 * @param LC 指向第三个有序表的指针
 */
void UnionList3(LinkList **LA, LinkList *LB, LinkList *LC)
{
    LinkList *pa = (*LA)->next, *pb = LB->next, *pc = LC->next, *r, *q; // pa，pb，pc分别为LA，LB，LC的指针
    (*LA)->next = NULL; // LA作为结果链表的头结点
    r = (*LA); // r始终指向LA的尾结点
    while(pa != NULL)
    {
        while(pb!= NULL && pb->data < pa->data)
        {
            pb = pb->next;
        }
        while(pc!= NULL && pc->data < pa->data)
        {
            pc = pc->next;
        }
        if(pb!= NULL && pc!= NULL && pa->data == pb->data && pa->data == pc->data) // pa是3个表中均包含的数据元素的结点
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        else // pa不是3个表中均包含的数据元素的结点
        {
            q = pa;
            pa = pa->next; // pa指向下一个结点
            free(q); // 释放无用结点
        }
    }
    r->next = NULL; // 尾结点的next置空
}
