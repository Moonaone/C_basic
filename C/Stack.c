#include <stdio.h>

/*
    ջ��һ��ֻ����һ�˽��в����ɾ�����������Ա�����������в����ɾ��������һ�˳�Ϊջ������һ�˳�Ϊջ�ס�
    ջ���ĵ�ǰλ���Ƕ�̬�仯�ģ�ջ��Ԫ�صĸ����Ǳ仯�ģ�ջ����ǰλ����һ����Ϊջ��ָ���λ��ָʾ��ָʾ��
    ��ջ��û��Ԫ��ʱ��Ϊ��ջ��ջ�Ĳ��������Ϊ��ջ����ջ��ջ��ɾ��������Ϊ��ջ����ջ��

    ջ����Ҫ�ص��Ǻ���ȳ��������ջ��Ԫ���ȳ�ջ��ջ�Ĳ��������ɾ����������ջ�����С�
*/

typedef char ElemType;

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

/**
 * @brief ��ȡջ��Ԫ��
 *
 * @param s ָ��ջ��ָ��
 * @param e ָ��Ҫ��ȡԪ�ص�ָ��
 * @return int ��ȡ�ɹ�����1�����򷵻�0
 */
int GetTop(SqStack *s, ElemType **e)
{
    if (s->top == -1) // ջ��
        return 0;
    *e = s->data[s->top];
    return 1;
}

/**
 * @brief ��ӡջ
 *
 * @param s ָ��ջ��ָ��
 */
void DisStack(SqStack *s)
{
    int i;
    for (i = s->top; i >= 0; i--)
        printf("%c ", s->data[i]);
    printf("\n");
}

/*
    ��дһ���㷨����˳��ջ�ж�һ���ַ����Ƿ��ǶԳƴ�����ν�Գƴ���ָ�������Ҷ��ʹ����������������ͬ��
*/

int symmertry(ElemType str[])
{
    int i ;
    ElemType e;
    SqStack *st;
    InitStack(st);
    for(i = 0; str[i] != '\0'; i++) // ���ַ�����ջ
        Push(st, str[i]);
    for(i = 0; str[i]!= '\0'; i++) // ���ַ�����ջ��Ԫ�رȽ�
    {
        Pop(st, e);
        if(str[i] != e)
            return 0;
    }
    return 1;
}

typedef struct linknode
{
    ElemType data; // ������
    struct linknode *next; // ָ����
}LiStack;

/**
 * @brief ��ʼ����ջ
 *
 * @param s ָ����ջ��ָ���ָ��
 */
void InitStack(LiStack **s)
{
    *s = (LiStack *)malloc(sizeof(LiStack));
    (*s)->next = NULL;
}

/**
 * @brief ������ջ
 *
 * @param s ָ����ջ��ָ���ָ��
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
    free(p); // ��ʱpָ�����һ���ڵ㣬�ͷ�p
}

/**
 * @brief ��ȡ��ջ�ĳ���
 *
 * @param s ָ����ջ��ָ��
 * @return int ������ջ�ĳ���
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
 * @brief �ж���ջ�Ƿ�Ϊ��
 *
 * @param s ָ����ջ��ָ��
 * @return int ��ջΪ�շ���1�����򷵻�0
 */
int StackEmpty(LiStack *s)
{
    return (s->next == NULL);
}

/**
 * @brief ����ջ�в���Ԫ��
 *
 * @param s ָ����ջ��ָ���ָ��
 * @param e Ҫ�����Ԫ��
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
 * @brief ����ջ�е���Ԫ��
 *
 * @param s ָ����ջ��ָ���ָ��
 * @param e ָ��Ҫ����Ԫ�ص�ָ��
 * @return int �����ɹ�����1�����򷵻�0
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
 * @brief ��ȡ��ջ��Ԫ��
 *
 * @param s ָ����ջ��ָ��
 * @param e ָ��Ҫ��ȡԪ�ص�ָ��
 * @return int ��ȡ�ɹ�����1�����򷵻�0
 */
int GetTop(LiStack *s, ElemType **e)
{
    if(s->next == NULL)
        return 0;
    *e = s->next->data;
    return 1;
}

/**
 * @brief ��ӡ��ջ
 *
 * @param s ָ����ջ��ָ��
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
    ��дһ���㷨�ж�����ı��ʽ�е������Ƿ����(����ֻ���������ź�������)��
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

// ջ��Ӧ�þ���

struct // ��������ȼ�
{
    char ch; // �����
    int pri; // ���ȼ�
}
lpri[] = {{'=', 0}, {'(', 1}, {'*', 5}, {'/', 5}, {'+', 3}, {'-', 3}, {')', 6}},
rpri[] = {{'=', 0}, {'(', 6}, {'*', 4}, {'/', 4}, {'+', 2}, {'-', 2}, {')', 1}};

int leftpri(char op) // ��ȡ����������ȼ�
{
    int i;
    for(i = 0; i < 7; i++)
        if(lpri[i].ch == op)
            return lpri[i].pri;
}

int rightpri(char op) // ��ȡ����������ȼ�
{
    int i;
    for(i = 0; i < 7; i++)
        if(rpri[i].ch == op)
            return rpri[i].pri;
}

int InOp(char ch) // �ж�ch�Ƿ�Ϊ�����
{
    if(ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int Precede(char op1, char op2) // �ж�op1��op2�����ȼ�
{
    if(leftpri(op1) == rightpri(op2))
        return 0;
    else if(leftpri(op1) < rightpri(op2))
        return -1;
    else
        return 1;
}

void trans(char exp[], char postexp[]) // ����׺���ʽת��Ϊ��׺���ʽ
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

float compvalue(char *postexp) // �����׺���ʽ��ֵ
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
                    printf("����");
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

// ���������

void main()
{
    char exp[] = "(56-20)/(4+2)";
    char postexp[MaxSize];
    trans(exp, postexp);
    printf("�м����ʽ:%s\n", exp);
    printf("��׺���ʽ:%s\n", postexp);
    printf("���ʽ��ֵ:%g\n", compvalue(postexp));
}

// ����Թ�����

// 0��ʾͨ·��1��ʾ�ϰ�

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
    int i; // �к�
    int j; // �к�
    int di; // di����һ�������ڷ�λ�����
} st[MaxSize]; // ����˳��ջ
int top = -1; // ��ʼ��ջ��ָ��

int mgpath(int xi, int yi, int xe, int ye) // ���·��Ϊ(xi, yi)��(xe, ye)���Թ�·��
{
    int i, j, k, di, find;
    top++; // ��ջ
    st[top].i = xi;
    st[top].j = yi;
    st[top].di = -1;
    mg[1][1] = -1; // ��ʾ�Ѿ��߹�
    while(top > -1)
    {
        i = st[top].i;
        j = st[top].j;
        k = st[top].di;
        if(i == xe && j == ye) // �ҵ�����
        {
            printf("�Թ�·������:\n");
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
        while(di < 4 && find == 0) // ����һ���������ڷ�λ
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
            if(mg[i][j] == 0) // �������ڷ�λ
                find = 1;
        }
        if(find == 1) // �ҵ��������ڷ�λ
        {
            st[top].di = di; // �޸�ԭջ��Ԫ�ص�diֵ
            top++; // ��ջ
            st[top].i = i;
            st[top].j = j;
            st[top].di = -1;
            mg[i][j] = -1; // ��ʾ�Ѿ��߹�
        }
        else // û�п������ڷ�λ
        {
            mg[st[top].i][st[top].j] = 0; // �ָ�Ϊ����
            top--; // ��ջ
        }
    }
    return 0;
}

void main()
{
    mgpath(1, 1, M, N);
}
