#include <stdio.h>

struct abc
{
    int a;
    short b;
    long c;
}__attribute__((packed));

// ��չ�����ݽṹ
struct efg
{
    char e;
    float f;
    int g;
}__attribute__((packed));

#pragma anon_union
struct package
{
    unsigned char id;
    union
    {
        unsigned char payload[24];
        struct abc a;
        // ��չ�����ݽṹ
        struct efg b;
    };
};

void send_package(void* data, int len)
{
    struct package* p = (struct package*)data;
    uart_send(p->id);
    for(int i = 0; i < len; i++)
    {
        uart_send(p->payload[i]);
    }
}
