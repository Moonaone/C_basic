#include <stdio.h>

/*
    栈是一种只能在一端进行插入和删除操作的线性表，表中允许进行插入和删除操作的一端称为栈顶，另一端称为栈底。
    栈顶的当前位置是动态变化的，栈中元素的个数是变化的，栈顶当前位置由一个称为栈顶指针的位置指示器指示。
    当栈中没有元素时称为空栈。栈的插入操作称为进栈或入栈，栈的删除操作称为出栈或退栈。

    栈的主要特点是后进先出，即后进栈的元素先出栈。栈的插入操作和删除操作都在栈顶进行。
*/

typedef char ElemType;

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

/**
 * @brief 获取栈顶元素
 *
 * @param s 指向栈的指针
 * @param e 指向要获取元素的指针
 * @return int 获取成功返回1，否则返回0
 */
int GetTop(SqStack *s, ElemType **e)
{
    if (s->top == -1) // 栈空
        return 0;
    *e = s->data[s->top];
    return 1;
}

/**
 * @brief 打印栈
 *
 * @param s 指向栈的指针
 */
void DisStack(SqStack *s)
{
    int i;
    for (i = s->top; i >= 0; i--)
        printf("%c ", s->data[i]);
    printf("\n");
}

/*
    编写一个算法利用顺序栈判断一个字符串是否是对称串，所谓对称串是指从左向右读和从右向左读的序列相同。
*/

int symmertry(ElemType str[])
{
    int i ;
    ElemType e;
    SqStack *st;
    InitStack(st);
    for(i = 0; str[i] != '\0'; i++) // 将字符串入栈
        Push(st, str[i]);
    for(i = 0; str[i]!= '\0'; i++) // 将字符串与栈中元素比较
    {
        Pop(st, e);
        if(str[i] != e)
            return 0;
    }
    return 1;
}

typedef struct linknode
{
    ElemType data; // 数据域
    struct linknode *next; // 指针域
}LiStack;

/**
 * @brief 初始化链栈
 *
 * @param s 指向链栈的指针的指针
 */
void InitStack(LiStack **s)
{
    *s = (LiStack *)malloc(sizeof(LiStack));
    (*s)->next = NULL;
}

/**
 * @brief 销毁链栈
 *
 * @param s 指向链栈的指针的指针
 */
void DestroyStack(LiStack **s)
{
    LiStack *p = *s, *q = (*s)->next;
    while(q != NULL)
    {
        free(p);
        p = q;
        q = q->next;
    }
    free(p); // 此时p指向最后一个节点，释放p
}

/**
 * @brief 获取链栈的长度
 *
 * @param s 指向链栈的指针
 * @return int 返回链栈的长度
 */
int StackLength(LiStack *s)
{
    int n  = 0;
    LiStack *p;
    p = s->next;
    while(p!= NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

/**
 * @brief 判断链栈是否为空
 *
 * @param s 指向链栈的指针
 * @return int 链栈为空返回1，否则返回0
 */
int StackEmpty(LiStack *s)
{
    return (s->next == NULL);
}

/**
 * @brief 向链栈中插入元素
 *
 * @param s 指向链栈的指针的指针
 * @param e 要插入的元素
 */
void Push(LiStack **s, ElemType e)
{
    LiStack *p;
    p = (LiStack *)malloc(sizeof(LiStack));
    p->data = e;
    p->next = (*s)->next;
    (*s)->next = p;
}

/**
 * @brief 从链栈中弹出元素
 *
 * @param s 指向链栈的指针的指针
 * @param e 指向要弹出元素的指针
 * @return int 弹出成功返回1，否则返回0
 */
int Pop(LiStack **s, ElemType *e)
{
    LiStack *p;
    if((*s)->next == NULL)
        return 0;
    p = (*s)->next;
    *e = p->data;
    (*s)->next = p->next;
    free(p);
    return 1;
}

/**
 * @brief 获取链栈顶元素
 *
 * @param s 指向链栈的指针
 * @param e 指向要获取元素的指针
 * @return int 获取成功返回1，否则返回0
 */
int GetTop(LiStack *s, ElemType **e)
{
    if(s->next == NULL)
        return 0;
    *e = s->next->data;
    return 1;
}

/**
 * @brief 打印链栈
 *
 * @param s 指向链栈的指针
 */
void DisStack(LiStack *s)
{
    LiStack *p = s->next;
    while(p!= NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*
    编写一个算法判断输入的表达式中的括号是否配对(假设只含有左括号和右括号)。
*/

int Match(ElemType exp[], int n)
{
    int i = 0;
    ElemType e;
    LiStack *st;
    InitStack(st);
    while(i < n)
    {
        if(exp[i] == '(')
            Push(st, exp[i]);
        else if(exp[i] == ')')
        {
            if(GetTop(st, e) == 1)
            {
                if(StackEmpty(st))
                    return 0;
                else
                    Pop(st, e);
            }
            else
                return 0;
        }
        i++;
    }
    if(StackEmpty(st))
        return 1;
    else
        return 0;
}

// 栈的应用举例

struct // 运算符优先级
{
    char ch; // 运算符
    int pri; // 优先级
}
lpri[] = {{'=', 0}, {'(', 1}, {'*', 5}, {'/', 5}, {'+', 3}, {'-', 3}, {')', 6}},
rpri[] = {{'=', 0}, {'(', 6}, {'*', 4}, {'/', 4}, {'+', 2}, {'-', 2}, {')', 1}};

int leftpri(char op) // 获取左运算符优先级
{
    int i;
    for(i = 0; i < 7; i++)
        if(lpri[i].ch == op)
            return lpri[i].pri;
}

int rightpri(char op) // 获取右运算符优先级
{
    int i;
    for(i = 0; i < 7; i++)
        if(rpri[i].ch == op)
            return rpri[i].pri;
}

int InOp(char ch) // 判断ch是否为运算符
{
    if(ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int Precede(char op1, char op2) // 判断op1和op2的优先级
{
    if(leftpri(op1) == rightpri(op2))
        return 0;
    else if(leftpri(op1) < rightpri(op2))
        return -1;
    else
        return 1;
}

void trans(char exp[], char postexp[]) // 将中缀表达式转换为后缀表达式
{
    struct
    {
        char data[MaxSize];
        int top;
    }op;
    int i = 0;
    op.top = -1;
    op.top++;
    op.data[op.top] = '=';
    while(exp[i] != '\0')
    {
        if(!InOp(*exp))
        {
            while(*exp >= '0' && *exp <= '9')
            {
                postexp[i++] = *exp;
                exp++;
            }
            postexp[i++] = '#';
        }
        else
        {
            switch(Precede(op.data[op.top], *exp))
            {
                case -1:
                    op.top++;
                    op.data[op.top] = *exp;
                    exp++;
                    break;
                case 0:
                    op.top--;
                    exp++;
                    break;
                case 1:
                    postexp[i++] = op.data[op.top];
                    op.top--;
                    break;
            }
        }
    }
    while(op.data[op.top]!= '=')
    {
        postexp[i++] = op.data[op.top];
        op.top--;
    }
    postexp[i] = '\0';
}

float compvalue(char *postexp) // 计算后缀表达式的值
{
    struct
    {
        float data[MaxSize];
        int top;
    }st;
    float d, a, b, c;
    st.top = -1;
    while(*postexp!= '\0')
    {
        switch(*postexp)
        {
            case '+':
                a = st.data[st.top];
                st.top--;
                b = st.data[st.top];
                st.top--;
                c = a + b;
                st.top++;
                st.data[st.top] = c;
                break;
            case '-':
                a = st.data[st.top];
                st.top--;
                b = st.data[st.top];
                st.top--;
                c = b - a;
                st.top++;
                st.data[st.top] = c;
                break;
            case '*':
                a = st.data[st.top];
                st.top--;
                b = st.data[st.top];
                st.top--;
                c = a * b;
                st.top++;
                st.data[st.top] = c;
                break;
            case '/':
                a = st.data[st.top];
                st.top--;
                b = st.data[st.top];
                st.top--;
                if(a != 0)
                {
                    c = b / a;
                    st.top++;
                    st.data[st.top] = c;
                }
                else
                {
                    printf("出错！");
                    exit(0);
                }
                break;
            default:
                d = 0;
                while(*postexp>= '0' && *postexp<= '9')
                {
                    d = 10 * d + *postexp - '0';
                    postexp++;
                }
                st.top++;
                st.data[st.top] = d;
                break;
        }
        postexp++;
    }
    return(st.data[st.top]);
}

// 设计求解程序

void main()
{
    char exp[] = "(56-20)/(4+2)";
    char postexp[MaxSize];
    trans(exp, postexp);
    printf("中极表达式:%s\n", exp);
    printf("后缀表达式:%s\n", postexp);
    printf("表达式的值:%g\n", compvalue(postexp));
}

// 求解迷宫问题

// 0表示通路，1表示障碍

#define M 10
#define N 10

int mg[M][N] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct
{
    int i; // 行号
    int j; // 列号
    int di; // di是下一可走相邻方位的序号
} st[MaxSize]; // 定义顺序栈
int top = -1; // 初始化栈顶指针

int mgpath(int xi, int yi, int xe, int ye) // 求解路径为(xi, yi)到(xe, ye)的迷宫路径
{
    int i, j, k, di, find;
    top++; // 进栈
    st[top].i = xi;
    st[top].j = yi;
    st[top].di = -1;
    mg[1][1] = -1; // 表示已经走过
    while(top > -1)
    {
        i = st[top].i;
        j = st[top].j;
        k = st[top].di;
        if(i == xe && j == ye) // 找到出口
        {
            printf("迷宫路径如下:\n");
            for(k = 0; k <= top; k++)
                {
                    printf("(%d, %d)\n", st[k].i, st[k].j);
                    if((k + 1) % 5 == 0) 
                    printf("\n");
                }
                printf("\n");
                return 1;
        }
        find = 0;
        while(di < 4 && find == 0) // 找下一个可走相邻方位
        {
            di++;
            switch(di)
            {
                case 0:
                    i = st[top].i - 1;
                    j = st[top].j;
                    break;
                case 1:
                    i = st[top].i;
                    j = st[top].j + 1;
                    break;
                case 2:
                    i = st[top].i + 1;
                    j = st[top].j;
                    break;
                case 3:
                    i = st[top].i;
                    j = st[top].j - 1;
                    break;
            }
            if(mg[i][j] == 0) // 可走相邻方位
                find = 1;
        }
        if(find == 1) // 找到可走相邻方位
        {
            st[top].di = di; // 修改原栈顶元素的di值
            top++; // 进栈
            st[top].i = i;
            st[top].j = j;
            st[top].di = -1;
            mg[i][j] = -1; // 表示已经走过
        }
        else // 没有可走相邻方位
        {
            mg[st[top].i][st[top].j] = 0; // 恢复为可走
            top--; // 出栈
        }
    }
    return 0;
}

void main()
{
    mgpath(1, 1, M, N);
}
