#include <stdio.h>

struct ListNode{
    int val; // ������
    struct ListNode *next; // ������һ���ڵ��ָ��
};

int main()
{
    int number = 5;
    int *ptr = &number;

    printf("number's address: %p\n", &number); // number�ĵ�ַ
    printf("number's value: %d\n", number);    // number��ֵ
    printf("ptr's address: %p\n", &ptr); // ptr�ĵ�ַ
    printf("ptr's value: %p\n", ptr);    // ptr��ֵ
    printf("ptr pointing value: %d\n", *ptr); // ptrָ���ֵ

    *ptr = 10;
    printf("number's value: %d\n", number);    // number��ֵ

    number = 15;

    printf("ptr pointing value: %d\n", *ptr); // ptrָ���ֵ

    struct ListNode a, b, c, d, e; // ����5������ڵ�
    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    e.val = 5;

    // ͨ��nextָ����������ڵ�
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    struct ListNode *head = &a; // ָ��headָ�������ͷ�ڵ�a
    while(head)
    {
        printf("val = [%d] adress = [%p] next = [%p]\n", head->val, head, head->next);
        head = head->next;
    }

    int num = 5;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;

    printf("num's address: %p\n", &num);
    printf("num's value: %d\n\n", num);

    printf("ptr1's address: %p\n", &ptr1);
    printf("ptr1's value: %p\n\n", ptr1);

    printf("ptr1 pointing value(*ptr1): %d\n\n", *ptr1);
    
    printf("ptr2's address: %p\n", &ptr2);
    printf("ptr2's value: %p\n\n", ptr2);

    printf("ptr2 pointing value(*ptr2): %p\n\n", *ptr2);
    printf("ptr2 pointing value(*ptr2): %p\n\n", **ptr2);

    printf("ptr3's address: %p\n", &ptr3);
    printf("ptr3's value: %p\n\n", ptr3);

    printf("ptr3 pointing value(*ptr3): %p\n\n", *ptr3);
    printf("ptr3 pointing value(*ptr3): %p\n\n", **ptr3);
    printf("ptr3 pointing value(*ptr3): %p\n\n", ***ptr3);

    return 0;
}
