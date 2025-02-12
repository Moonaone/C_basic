#include <stdio.h>

/*
    【【强烈推荐】深入浅出数据结构 - 顶尖程序员图文讲解 - UP主翻译校对 (已完结)】https://www.bilibili.com/video/BV1Fv4y1f7T1?p=5&vd_source=d909ad0c2722953f57e98a59bca58cfc
*/

/*
    线性表
    线性表是由零个或多个数据元素组成的有限序列

    首先它是一个序列，也就是元素之间有顺序，若元素存在多个，则第一个元素无前驱，最后一个元素无后继，其他每个元素都有且只有一个前驱和后继。
    另外，线性表强调是有限的，无论计算机发展到多强大，都不能表示无限个数据元素。

    线性表的抽象数据类型定义：
    若将线性表记为(a1, a2, ..., ai-1, ai, ai+1, ..., an),则表中ai-1领先于ai，ai领先于ai+1，称ai-1是ai的直接前驱元素，ai+1是ai的直接后继元素。
    所以线性表元素的个数n(n>=0)定义为线性表的长度，当n=0时，称为空表。

    数据类型:是指一组性质相同的值的集合及定义在此集合上的一些操作的总称。
    例如很多编程语言的整形、浮点型、字符型等，它们都是数据类型。
*/

/*
    假设有两个集合A和B分别用两个线性表La和Lb表示，即线性表中的数据元素即为集合中的成员。编写一个函数，求一个新的集合C=AUB。
*/

/*
void unionList(List LA, List LB, List &LC)
{
    int lena, i;
    ElemType e;
    InitList(LC);
    for(i = 1; i <= ListLength(LA); i++)
    {
        GetElem(LA, i, e);
        ListInsert(LC, 1, e);
    }
    lena = ListLength(LA);
    for(i = 1; i <= ListLength(LB); i++)
    {
        GetElem(LB, i, e);
        if(!LocateElem(LA, e))
        {
            ListInsert(LC, ++lena, e);
        }
    }
}
*/

/*
    线性表的顺序表示和实现
    线性表的顺序存储结构就是，把线性表中的所有元素按照其逻辑顺序，依次存储到从计算机存储的起始位置开始的一块连续的存储空间中。这样，线性表中第一个数据元素的存储位置就是存储空间的起始位置，之后的每个数据元素的存储位置都依此递增。
    线性表的顺序存储结构是利用数组来实现的。数组的基本类型就是线性表中元素的类型，数组的大小要大于等于线性表的长度。线性表中的第一个元素存储在数组的第一个位置。
*/

#define MaxSize 50

typedef char ElemType;

typedef struct{
    ElemType data[MaxSize]; // 存放顺序表元素
    int length; // 存放顺序表的长度
}SqList; // 顺序表的类型定义

/**
 * @brief 由a中的n个元素建立顺序表
 * 
 * @param L 指向顺序表的指针的指针
 * @param a 用于初始化顺序表的数组
 * @param n 数组的长度
 */
void CreateList(SqList **L, ElemType a[], int n)
{
    int i;
    // 分配存放线性表的空间
    *L = (SqList *)malloc(sizeof(SqList));
    for(i = 0; i < n; i++)
    {
        (*L)->data[i] = a[i];
    }
    (*L)->length = n;
}

/**
 * @brief 初始化顺序表
 * 
 * @param L 指向顺序表的指针的指针
 * 
 * @details 该函数用于初始化一个顺序表，为其分配内存空间，并将长度设置为0。
 *          首先，通过malloc函数为顺序表分配内存空间，大小为SqList类型的大小。
 *          然后，将顺序表的长度设置为0，表示该顺序表为空表。
 */

void InitList(SqList **L)
{
    // 分配存放线性表的空间
    (*L) = (SqList *)malloc(sizeof(SqList));
    (*L)->length = 0;
}

/**
 * @brief 销毁顺序表
 *
 * @param L 指向顺序表的指针的指针
 *
 * @details 该函数用于销毁一个顺序表，释放其占用的内存空间。
 *          首先，判断顺序表是否为空，如果为空，则直接返回。
 *          然后，使用free函数释放顺序表占用的内存空间。
 */
void DestroyList(SqList **L)
{
    free(*L);
}

/**
 * @brief 判断顺序表是否为空
 *
 * @param L 指向顺序表的指针的指针
 *
 * @return 如果顺序表为空，则返回1；否则返回0
 *
 * @details 该函数用于判断一个顺序表是否为空。
 */
int ListEmpty(SqList *L)
{
    return (L->length == 0);
}

/**
 * @brief 求顺序表的长度
 *
 * @param L 指向顺序表的指针的指针
 *
 * @return 顺序表的长度
 *
 * @details 该函数用于求一个顺序表的长度。
 */
int ListLength(SqList *L)
{
    return (L->length);
}

/**
 * @brief 输出顺序表
 *
 * @param L 指向顺序表的指针的指针
 *
 * @details 该函数用于输出一个顺序表的所有元素。
 *          首先，判断顺序表是否为空，如果为空，则直接返回。
 *          然后，使用for循环遍历顺序表中的所有元素，并输出它们的值。
 */
void DispList(SqList *L)
{
    int i;
    if(ListEmpty(L))
    {
        return;
    }
    for(i = 0; i < L->length; i++)
    {
        printf("%c ", L->data[i]);
    }
    printf("\n");
}

/**
 * @brief 求顺序表L中第i个位置的元素值
 *
 * @param L 指向顺序表的指针的指针
 * @param i 要获取元素的位置
 * @param e 用于存储获取到的元素值
 *
 * @return 如果获取成功，则返回1；否则返回0
 */
int GetElem(SqList *L, int i, ElemType *e)
{
    if(i < 1 || i > L->length)
    {
        return 0;
    }
    *e = L->data[i - 1];
    return 1;
}

/**
 * @brief 查找第一个元素值等于e的元素
 *
 * @param L 指向顺序表的指针的指针
 * @param e 要查找的元素值
 *
 * @return 如果找到，则返回该元素的位置；否则返回0
 */
int LocateElem(SqList *L, ElemType e)
{
    int i = 0;
    while(i < L->length && L->data[i] != e)
    {
        i++;
    }
    if(i >= L->length)
    {
        return 0;
    }
    else
    {
        return i + 1;
    }
}

/**
 * @brief 在顺序表L的第i个位置插入新元素e
 *
 * @param L 指向顺序表的指针的指针
 * @param i 要插入的位置
 * @param e 要插入的元素值
 *
 * @return 如果插入成功，则返回1；否则返回0
 */
int ListInsert(SqList **L, int i, ElemType e)
{
    int j;
    if(i < 1 || i > (*L)->length + 1)
    {
        return 0;
    }
    i--;
    for(j = (*L)->length; j > i; j--)
    {
        (*L)->data[j] = (*L)->data[j - 1];
    }
    (*L)->data[i] = e;
    (*L)->length++;
    return 1;
}

/**
 * @brief 删除顺序表L中第i个位置的元素，并用e返回其值
 *
 * @param L 指向顺序表的指针的指针
 * @param i 要删除的位置
 * @param e 用于存储删除的元素值
 *
 * @return 如果删除成功，则返回1；否则返回0
 */
int ListDelete(SqList **L, int i, ElemType *e)
{
    int j;
    if(i < 1 || i > (*L)->length)
    {
        return 0;
    }
    i--;
    *e = (*L)->data[i];
    for(j = i; j < (*L)->length - 1; j++)
    {
        (*L)->data[j] = (*L)->data[j + 1];
    }
    (*L)->length--;
    return 1;
}

/*
    有一个顺序表A。设计一个算法，删除所有元素值在[x,y]之间的所有元素，要求算法的时间复杂度为O(n)，空间复杂度为O(1)。
*/

/**
 * @brief 删除顺序表A中所有元素值在[x,y]之间的元素
 *
 * @param L 指向顺序表的指针的指针
 * @param x 要删除的元素值的下界
 * @param y 要删除的元素值的上界
 *
 * @details 该函数用于删除顺序表A中所有元素值在[x,y]之间的元素。
*/
void dekekem(SqList **L, ElemType x, ElemType y)
{
    int i = 0, j = 0; // 扫描顺序表，j累计不满足条件的元素
    while(i < (*L)->length)
    {
        if(!((*L)->data[i] >= x && (*L)->data[i] <= y))
        {
            (*L)->data[j] = (*L)->data[i]; // 保存不满足条件的元素
            j++; // 不满足条件的元素个数加1
        }
        i++;
    }
    (*L)->length = j; // 更新顺序表的长度
}

/*
    有一个顺序表L，假设元素类型ElemType为整型并且所有元素均不相等，设计一个算法，以第一个元素为分界点，将所有小于它的元素移到前面，所有大于它的元素移到后面。
*/

/** 解法一
 * @brief 将顺序表L中的元素按照第一个元素为分界点，将所有小于它的元素移到前面，所有大于它的元素移到后面
 *
 * @param L 指向顺序表的指针的指针
 */
void move1(SqList **L)
{
    int i = 0, j = (*L)->length - 1; // 扫描顺序表，i从前往后扫描，j从后往前扫描
    ElemType pivot = (*L)->data[0]; // 第一个元素作为分界点
    ElemType temp; // 用于交换元素
    while(i != j)
    {
        while(i < j && (*L)->data[i] < pivot)
        {
            i--;
        }
        while(i < j && (*L)->data[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            temp = (*L)->data[i];
            (*L)->data[i] = (*L)->data[j];
            (*L)->data[j] = temp;
        }
    }
}

/** 解法二
 * @brief 将顺序表L中的元素按照第一个元素为分界点，将所有小于它的元素移到前面，所有大于它的元素移到后面
 *
 * @param L 指向顺序表的指针的指针
 */
void movel2(SqList **L)
{
    int i = 0, j = (*L)->length - 1; // 扫描顺序表，i从前往后扫描，j从后往前扫描
    ElemType pivot = (*L)->data[0]; // 第一个元素作为分界点
    while(i != j)
    {
        while(i < j && (*L)->data[j] > pivot)
            j--; // 从后往前扫描，找到第一个小于pivot的元素
        (*L)->data[i] = (*L)->data[j]; // 将该元素放到i的位置
        while(i < j && (*L)->data[i] < pivot)
            i++; // 从前往后扫描，找到第一个大于pivot的元素
        (*L)->data[j] = (*L)->data[i]; // 将该元素放到j的位置
    }
    (*L)->data[i] = pivot;
}

/*
    在链式存储中，每个存储结点不仅包含有元素本身的信息(称之为数据域)，还要包含有元素之间逻辑关系的信息(称之为指针域)。
    一般的，每个结点有一个或多个这样的指针域。
    若一个结点中的某个指针域不需要指向任何结点，则将其置为NULL。

    在每个结点中除包含有数据域外，只设置一个指针域，这样的链表称为单链表。
    在每个结点中除包含有数据域外，设置两个指针域，这样的链表称为双链表。

    单链表只能访问其直接后继结点，而双链表可以访问其直接后继结点和直接前驱结点。
*/

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

/*
    存储密度是指结点数据本身所占的存储量和整个结点结构所占的存储量之比。
    一般的，存储密度越大，存储空间的利用率就越高。
*/

// 头插法建表
/**
 * @brief 头插法创建单链表
 * 
 * @param L 指向单链表头指针的指针
 * @param a 用于初始化单链表的数组
 * @param n 数组的长度
 */
void CreateListF(LinkList **L, ElemType a[], int n)
{
    LinkList *s;
    int i;
    *L = (LinkList *)malloc(sizeof(LinkList)); // 创建头结点
    (*L)->next = NULL; // 头结点的指针域置空
    for(i = 0; i < n; i++)
    {
        s = (LinkList *)malloc(sizeof(LinkList)); // 创建新结点
        s->data = a[i]; // 新结点的数据域赋值
        s->next = (*L)->next; // 新结点的指针域指向头结点的后继结点
        (*L)->next = s; // 头结点的指针域指向新结点
    }
}

// 尾插法建表
/**
 * @brief 尾插法创建单链表
 *
 * @param L 指向单链表头指针的指针
 * @param a 用于初始化单链表的数组
 * @param n 数组的长度
 */
void CreateListR(LinkList **L, ElemType a[], int n)
{
    LinkList *s, *r;
    int i;
    *L = (LinkList *)malloc(sizeof(LinkList)); // 创建头结点
    r = *L; // r指向尾结点
    for(i = 0; i < n; i++)
    {
        s = (LinkList *)malloc(sizeof(LinkList)); // 创建新结点
        s->data = a[i]; // 新结点的数据域赋值
        r->next = s; // 尾结点的指针域指向新结点
        r = s; // r指向新结点
    }
    r->next = NULL; // 尾结点的指针域置空
}

// 线性表基本运算实现
/**
 * @brief 初始化单链表
 * 
 * @param L 指向单链表头指针的指针
 * 
 * @details 该函数用于初始化一个单链表，为其分配内存空间，并将头结点的指针域置空。
 *          首先，通过malloc函数为单链表分配内存空间，大小为LinkList类型的大小。
 *          然后，将头结点的指针域置空，表示该单链表为空表。
 */
void InitList(LinkList **L)
{
    *L = (LinkList *)malloc(sizeof(LinkList)); // 创建头结点
    (*L)->next = NULL; // 头结点的指针域置空
}

/**
 * @brief 销毁单链表
 *
 * @param L 指向单链表头指针的指针
 *
 * @details 该函数用于销毁一个单链表，释放其占用的内存空间。
 *          首先，判断单链表是否为空，如果为空，则直接返回。
 *          然后，使用while循环遍历单链表中的所有结点，并释放它们占用的内存空间。
 */
void DestroyList(LinkList **L)
{
    LinkList *p = *L, *q = p->next;
    while(q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p); // 释放最后一个结点占用的内存空间
}

/**
 * @brief 判断单链表是否为空
 *
 * @param L 指向单链表头指针的指针
 *
 * @return 如果单链表为空，则返回1；否则返回0
 *
 * @details 该函数用于判断一个单链表是否为空。
 */
int ListEmpty(LinkList *L)
{
    return (L->next == NULL);
}

/**
 * @brief 求单链表的长度
 *
 * @param L 指向单链表头指针的指针
 *
 * @return 单链表的长度
 *
 * @details 该函数用于求一个单链表的长度。
 */
int ListLength(LinkList *L)
{
    int n = 0;
    LinkList *p = L;
    while(p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

/**
 * @brief 输出单链表
 *
 * @param L 指向单链表头指针的指针
 *
 * @details 该函数用于输出一个单链表的所有元素。
 *          首先，判断单链表是否为空，如果为空，则直接返回。
 *          然后，使用while循环遍历单链表中的所有结点，并输出它们的数据域的值。
 */
void DispList(LinkList *L)
{
    LinkList *p = L->next;
    while(p!= NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * @brief 求单链表L中第i个位置的元素值
 *
 * @param L 指向单链表头指针的指针
 * @param i 要获取元素的位置
 * @param e 用于存储获取到的元素值
 *
 * @return 如果获取成功，则返回1；否则返回0
 */
int GetElem(LinkList *L, int i, ElemType *e)
{
    int j = 0;
    LinkList *p = L;
    while(j < i && p!= NULL)
    {
        j++;
        p = p->next;
    }
    if(p== NULL)
    {
        return 0;
    }
    else
    {
        *e = p->data;
        return 1;
    }
}

/**
 * @brief 查找第一个元素值等于e的元素
 *
 * @param L 指向单链表头指针的指针
 * @param e 要查找的元素值
 *
 * @return 如果找到，则返回该元素的位置；否则返回0
 */
int LocateElem(LinkList *L, ElemType e)
{
    LinkList *p = L->next;
    int i = 1;
    while(p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

/**
 * @brief 在单链表L的第i个位置插入新元素e
 *
 * @param L 指向单链表头指针的指针
 * @param i 要插入的位置
 * @param e 要插入的元素值
 *
 * @return 如果插入成功，则返回1；否则返回0
 */
int ListInsert(LinkList **L, int i, ElemType e)
{
    int j = 0;
    LinkList *p = *L, *s;
    while(j < i - 1 && p!= NULL)
    {
        j++;
        p = p->next;
    }
    if(p== NULL)
    {
        return 0;
    }
    else
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}

/**
 * @brief 删除单链表L中第i个位置的元素，并用e返回其值
 *
 * @param L 指向单链表头指针的指针
 * @param i 要删除的位置
 * @param e 用于存储删除的元素值
 *
 * @return 如果删除成功，则返回1；否则返回0
 */
int ListDelete(LinkList **L, int i, ElemType *e)
{
    int j = 0;
    LinkList *p = *L, *q;
    while(j < i - 1 && p!= NULL)
    {
        j++;
        p = p->next;
    }
    if(p== NULL)
    {
        return 0;
    }
    else
    {
        q = p->next;
        if(q == NULL)
        {
            return 0;
        }
        *e = q->data;
        p->next = q->next;
        free(q);
        return 1;
    }
}

/*
    有一个带头结点的单链表L = {a1, b1, a2, b2, ..., an, bn}，设计一个算法，将其拆分为两个带头结点的单链表L1 = {a1, a2, ..., an}和L2 = {bn, ..., b2, b1}，要求L1使用L的头结点。
*/
/**
 * @brief 将带头结点的单链表L拆分为两个带头结点的单链表L1和L2
 *
 * @param L 指向单链表头指针的指针
 * @param L1 指向单链表L1头指针的指针
 * @param L2 指向单链表L2头指针的指针
 */
void split(LinkList **L, LinkList **L1, LinkList **L2)
{
    LinkList *p = (*L)->next, *q, *r1;
    *L1 = *L;
    r1 = L1;
    *L2 = (LinkList *)malloc(sizeof(LinkList));
    (*L2)->next = NULL;
    while(p!= NULL)
    {
        q = p->next;
        r1->next = p;
        r1 = p;
        p = q->next;
        q->next = (*L2)->next;
        (*L2)->next = q;
    }
    r1->next = NULL;
} 

/* 
    有一个带头结点的电链表L,设计一个算法使其元素递增有序排列
*/
/**
 * @brief 对单链表进行排序
 * 
 * @param L 指向单链表头指针的指针
 * 
 * @details 该函数用于对一个单链表进行排序，使其元素递增有序排列。
 *          首先，判断单链表是否为空，如果为空，则直接返回。
 *          然后，使用while循环遍历单链表中的所有结点，并将它们按照递增顺序插入到一个新的单链表中。
 *          最后，将新的单链表的头结点指向原单链表的头结点，完成排序。
 */
void sort(LinkList **L)
{
    LinkList *p = (*L)->next, *q, *r; // p指向原单链表的第一个结点，q指向新单链表的最后一个结点，r指向原单链表的下一个结点
    if(p != NULL) // 若原单链表中有一个或以上的数据结点
    {
        r = p->next; // r保存*p结点后继结点的指针
        p->next = NULL; // 构造只含一个数据结点的有序表
        p = r;
        while(p != NULL)
        {
            r = p->next; // r保存*p结点后继结点的指针
            q = *L;
            while(q->next!= NULL && q->next->data < p->data)
            {
                q = q->next; // 在有序表中查找插入*p的前驱结点*q
            }
            p->next = q->next; // 将*p插入到*q之后
            q->next = p;
            p = r; // 继续扫描原单链表
        }
    }
}

// 头插法建立双链表
/**
 * @brief 头插法创建双链表
 *
 * @param L 指向双链表头指针的指针
 * @param a 用于初始化双链表的数组
 * @param n 数组的长度
 */
void CreateListF(DLinkList **L, ElemType a[], int n)
{
    DLinkList *s;
    int i;
    *L = (DLinkList *)malloc(sizeof(DLinkList)); // 创建头结点
    (*L)->prior = NULL; // 头结点的prior指针置空
    (*L)->next = NULL; // 头结点的next指针置空
    for(i = 0; i < n; i++)
    {
        s = (DLinkList *)malloc(sizeof(DLinkList)); // 创建新结点
        s->data = a[i]; // 新结点的数据域赋值
        s->next = (*L)->next; // 新结点的next指针指向头结点的后继结点
        if((*L)->next!= NULL)
        {
            (*L)->next->prior = s; // 头结点的后继结点的prior指针指向新结点
        }
        (*L)->next = s; // 头结点的next指针指向新结点
        s->prior = *L; // 新结点的prior指针指向头结点
    }
}

// 尾插法建立双链表
/**
 * @brief 尾插法创建双链表
 *
 * @param L 指向双链表头指针的指针
 * @param a 用于初始化双链表的数组
 * @param n 数组的长度
 */
void CreateListR(DLinkList **L, ElemType a[], int n)
{
    DLinkList *s, *r;
    int i;
    *L = (DLinkList *)malloc(sizeof(DLinkList)); // 创建头结点
    r = *L; // r指向尾结点
    r->prior = NULL; // 尾结点的prior指针置空
    r->next = NULL; // 尾结点的next指针置空
    for(i = 0; i < n; i++)
    {
        s = (DLinkList *)malloc(sizeof(DLinkList)); // 创建新结点
        s->data = a[i]; // 新结点的数据域赋值
        r->next = s; // 尾结点的next指针指向新结点
        s->prior = r; // 新结点的prior指针指向尾结点
        r = s; // r指向新结点
    }
    r->next = NULL; // 尾结点的next指针置空
}

/**
 * @brief 在双链表L中的第i个位置插入新元素e
 *
 * @param L 指向双链表头指针的指针
 * @param i 要插入的位置
 * @param e 要插入的元素值
 *
 * @return 如果插入成功，则返回1；否则返回0
 */
int ListInsert(DLinkList **L, int i, ElemType e)
{
    int j = 0;
    DLinkList *p = *L, *s;
    while(j < i - 1 && p!= NULL)
    {
        j++;
        p = p->next;
    }
    if(p== NULL)
    {
        return 0;
    }
    else
    {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data = e;
        s->next = p->next;
        if(p->next != NULL)
        {
            p->next->prior = s;
        }
        s->prior = p;
        p->next = s;
        return 1;
    }
}

/**
 * @brief 在双链表L中的第i个位置删除元素e
 *
 * @param L 指向双链表头指针的指针
 * @param i 要删除的位置
 * @param e 用于存储删除的元素值
 *
 * @return 如果删除成功，则返回1；否则返回0
 */
int ListDelete(DLinkList **L, int i, ElemType *e)
{
    int j = 0; // p指向头结点
    DLinkList *p = *L, *q;
    while(j < i - 1 && p != NULL) // 循环找到第i-1个结点
    {
        j++;
        p = p->next;
    }
    if(p == NULL) // 未找到第i-1个结点
    {
        return 0;
    }
    else
    {
        q = p->next; // 找到逻辑位序为i-1的结点*p
        if(q == NULL) // q指向要删除的结点
        {
            return 0;
        }
        *e = q->data;
        p->next = q->next; // 从单链表中删除*q结点
        if(q->next != NULL)
        {
            q->next->prior = p;
        }
        free(q); // 释放*q结点
        return 1;
    }
}

/*
    一个带头结点的双链表L，设计一个算法，将L中所有元素逆置，即第一个元素成为最后一个元素，最后一个元素成为第一个元素。
*/

/**
 * @brief 对双链表进行逆置
 *
 * @param L 指向双链表头指针的指针
 */
void reverse(DLinkList **L)
{
    DLinkList *p = (*L)->next, *q; // p指向原双链表的第一个结点，q指向原双链表的第二个结点
    (*L)->next = NULL;
    while(p != NULL)
    {
        q = p->next; // q指向*p结点的后继结点
        p->next = (*L)->next; // 采用头插法将*p结点插入到双链表中
        if((*L)->next != NULL)
        {
            (*L)->next->prior = p;
        }
        p->prior = *L;
        (*L)->next = p;
        p = q;
    }
}

/*
    有一个带头结点的双链表L,设计一个算法使其元素递增有序排列
*/

/**
 * @brief 对双链表进行排序
 *
 * @param L 指向双链表头指针的指针
 */
void sort(DLinkList **L)
{
    DLinkList *p = (*L)->next, *q, *r; // p指向原双链表的第一个结点，q指向新双链表的最后一个结点，r指向原双链表的下一个结点
    if(p!= NULL) // 若原双链表中有一个或以上的数据结点
    {
        r = p->next; // r保存*p结点后继结点的指针
        p->next = NULL; // 构造只含一个数据结点的有序表
        p = r;
        while(p!= NULL)
        {
            r = p->next; // r保存*p结点后继结点的指针
            q = *L;
            while(q->next!= NULL && q->next->data < p->data)
            {
                q = q->next; // 在有序表中查找插入*p的前驱结点*q
            }
            p->next = q->next; // 将*p插入到*q之后
            if(q->next!= NULL)
            {
                q->next->prior = p;
            }
            q->next = p;
            p->prior = q;
            p = r;
        }
    }
}

/*
    有一个带头结点的循环单链表L,设计一个算法统计其data域值等于x的结点个数
*/

/**
 * @brief 统计循环单链表中data域值等于x的结点个数
 *
 * @param L 指向循环单链表头指针的指针
 * @param x 要统计的元素值
 *
 * @return 循环单链表中data域值等于x的结点个数
 */
int count(LinkList *L, ElemType x)
{
    int n = 0;
    LinkList *p = L->next; // p指向第一个结点
    while(p!= L)
    {
        if(p->data == x)
        {
            n++; // 找到后用n累加个数
        }
        p = p->next;
    }
    return n;
}

/*
    有一个带头结点的循环双链表L,设计一个算法删除第一个data域值等于x的结点
*/

/**
 * @brief 删除循环双链表中第一个data域值等于x的结点
 *
 * @param L 指向循环双链表头指针的指针
 * @param x 要删除的元素值
 *
 * @return 如果删除成功，则返回1；否则返回0
 */
int deletem(LinkList **L, ElemType x)
{
    DLinkList *p = (*L)->next; // p指向第一个结点
    while(p != L && p->data != x)
    {
        p = p->next;
    }
    if(p != L) // 找到第一个data域值等于x的结点
    {
        p->next->prior = p->prior;
        p->prior->next = p->next;
        free(p);
        return 1;
    }
    else
    {
        return 0;
    }
}

// 线性表的应用——笛卡尔积
#define MaxCol 10 // 最大列数

// typedef int ElemType; // 定义元素类型

typedef struct Nude1 // 定义数据结点类型
{
    ElemType data[MaxCol];
    struct Node1 *next; // 指向下一行的指针
}DList;

typedef struct Node2 // 定义表头结点类型
{
    int Row, Col; // 行号和列号
    DList *next; // 指向第一个数据结点
}HList;

void CrreateTable(HList **h)
{
    int i, j;
    DList *r, *s;
    *h = (HList *)malloc(sizeof(HList)); // 创建表头结点
    (*h)->next = NULL;
    printf("表的行数和列数：");
    scanf("%d%d", &(*h)->Row, &(*h)->Col);
    for(i = 0; i < (*h)->Row; i++)
    {
        printf("第%d行的元素：", i + 1);
        s = (DList *)malloc(sizeof(DList)); // 创建数据结点
        for(j = 0; j < (*h)->Col; j++) // 输入一行的数据初步统计
        {
            scanf("%d", &s->data[j]);
        }
        if((*h)->next == NULL) // 插入第一个数据结点
        {
            (*h)->next = s;
        }
        else // 插入其他数据结点
        {
            r->next = s; // 将*s插入到*r之后
        }
        r = s; // r指向最后一个数据结点
    }
    r->next = NULL; // 尾结点的next指针置空
}

void DisplayTable(HList *h)
{
    DList *p = h->next;
    while(p != NULL)
    {
        for(int i = 0; i < h->Col; i++)
        {
            printf("%d ", p->data[i]);
        }
        printf("\n");
        p = p->next;
    }
}

void LinkTable(HList *h1, HList *h2, HList **h)
{
    int i, j, k;
    DList *p = h1->next, *q, *r, *s;
    printf("连接字段是:第一个表位序,第二个表位序:");
    scanf("%d%d", &i, &j);
    *h = (HList *)malloc(sizeof(HList));
    (*h)->Row = 0;
    (*h)->Col = h1->Col + h2->Col;
    (*h)->next = NULL;
    while(p!= NULL)
    {
        q = h2->next;
        while(q!= NULL)
        {
            if(p->data[i - 1] == q->data[j - 1]) // 找到匹配的行
            {
                s = (DList *)malloc(sizeof(DList));
                for(k = 0; k < h1->Col; k++)
                {
                    s->data[k] = p->data[k];
                }
                for(k = 0; k < h2->Col; k++)
                {
                    s->data[h1->Col + k] = q->data[k];
                }
                if((*h)->next == NULL)
                {
                    (*h)->next = s;
                }
                else
                {
                    r->next = s;
                }
                r = s;
                (*h)->Row++;
            }
            q = q->next;
        }
        p = p->next;
    }
    r->next = NULL;
}

void main()
{
    HList *h1, *h2, *h;
    printf("第一个表：\n");
    CrreateTable(h1);
    printf("第二个表：\n");
    CrreateTable(h2);
    LinkTable(h1, h2, h);
    printf("连接后的表：\n");
    DisplayTable(h);
}

