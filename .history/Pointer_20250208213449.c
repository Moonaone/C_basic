#include <stdio.h>

struct ListNode{
    int val; // 数据域
    struct ListNode *next; // 连接下一个节点的指针
};

int main()
{
    int number = 5;
    int *ptr = &number;

    printf("number's address: %p\n", &number); // number的地址
    printf("number's value: %d\n", number);    // number的值
    printf("ptr's address: %p\n", &ptr); // ptr的地址
    printf("ptr's value: %p\n", ptr);    // ptr的值
    printf("ptr pointing value: %d\n", *ptr); // ptr指向的值

    *ptr = 10;
    printf("number's value: %d\n", number);    // number的值

    number = 15;

    printf("ptr pointing value: %d\n", *ptr); // ptr指向的值

    struct ListNode a, b, c, d, e; // 创建5个链表节点
    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    e.val = 5;

    // 通过next指针连接链表节点
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    struct ListNode *head = &a; // 指针head指向链表的头节点a
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
