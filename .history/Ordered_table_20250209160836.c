#include <stdio.h>

#define MaxSize 50

typedef char ElemType;

typedef struct{
    ElemType data[MaxSize]; // ���˳���Ԫ��
    int length; // ���˳���ĳ���
}SqList; // ˳�������Ͷ���

typedef struct LNode
{
    ElemType data; // ������
    struct LNode *next; // ָ����, ָ���̽��
}LinkList; // ����������Ͷ���

typedef struct DNode
{
    ElemType data; // ������
    struct DNode *prior; // ָ����, ָ��ֱ��ǰ�����
    struct DNode *next; // ָ����, ָ��ֱ�Ӻ�̽��
}DLinkList; // ˫��������Ͷ���

/**
 * @brief ������˳����в���Ԫ��
 * 
 * @param L ָ��˳����ָ���ָ��
 * @param e Ҫ�����Ԫ��
 * @return int ����ɹ�����1��Ԫ���Ѵ��ڷ���0
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
    ���Ա���������������ڣ�
        ���Ա�������ģ�������������
*/

/*
    ���������������LA��LB�����һ���㷨�������Ǻϲ���һ�������LC(����LA��LB��Ԫ�ؾ�����ͬ)��Ҫ��Ҫ�ƻ�LA��LB
*/

/**
 * @brief ����˳���ϲ����������
 *
 * @param LA ָ���һ��������ָ��
 * @param LB ָ��ڶ���������ָ��
 * @param LC ָ��ϲ����������ָ���ָ��
 */
void UnionList1(SqList *LA, SqList *LB, SqList **LC)
{
    int i = 0, j = 0, k = 0; // i��j��k�ֱ�ΪLA��LB��LC���±�
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
 * @brief ���õ�����ϲ����������
 *
 * @param LA ָ���һ��������ָ��
 * @param LB ָ��ڶ���������ָ��
 * @param LC ָ��ϲ����������ָ���ָ��
 */
void UnionList2(LinkList *LA, LinkList *LB, LinkList **LC)
{
    LinkList *pa = LA->next, *pb = LB->next, *pc, *s; // pa��pb��pc�ֱ�ΪLA��LB��LC��ָ��
    (*LC) = (LinkList *)malloc(sizeof(LinkList)); // ����ͷ���
    pc = (*LC); // pcʼ��ָ��LC��β���
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
    ��֪3����ͷ���ĵ�����LA��LB��LC�еĽ�����ֵ�ǵݼ���������(����ÿ����������������ֵ��ͬ�Ľ�㣬�������������п��ܴ�����ֵͬ�Ľ��)����дһ���㷨��LA����������²�����ʹ�����������LA�н�����3�����о�����������Ԫ�صĽ�㣬��û���ظ�����Ԫ��(���磺LA={1,2,3,4,5}��LB={1,2,3,4,5}��LC={1,2,3,4,5}����������LA={1,2,3,4,5})�����ͷ�LA���������ý�㣬Ҫ���㷨��ʱ�临�Ӷ�ΪO(n+m+p)������n��m��p�ֱ�ΪLA��LB��LC�ĳ���
*/

/**
 * @brief ��LA������в���
 *
 * @param LA ָ���һ��������ָ��
 * @param LB ָ��ڶ���������ָ��
 * @param LC ָ�������������ָ��
 */
void UnionList3(LinkList **LA, LinkList *LB, LinkList *LC)
{
    LinkList *pa = (*LA)->next, *pb = LB->next, *pc = LC->next, *r, *q; // pa��pb��pc�ֱ�ΪLA��LB��LC��ָ��
    (*LA)->next = NULL; // LA��Ϊ��������ͷ���
    r = (*LA); // rʼ��ָ��LA��β���
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
        if(pb!= NULL && pc!= NULL && pa->data == pb->data && pa->data == pc->data) // pa��3�����о�����������Ԫ�صĽ��
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        else // pa����3�����о�����������Ԫ�صĽ��
        {
            q = pa;
            pa = pa->next; // paָ����һ�����
            free(q); // �ͷ����ý��
        }
    }
    r->next = NULL; // β����next�ÿ�
}
