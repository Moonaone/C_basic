#include <stdio.h>
#include <string.h>

// 基类
struct shape
{
    int width;
    int height;
    void (*setWidth)(struct shape *s, int w);
    void (*setHeight)(struct shape *s, int h);
};

void setWidth(struct shape *s, int w)
{
    s->width = w;
}

void setHeight(struct shape *s, int h)
{
    s->height = h;
}

// 派生类
struct rectangle
{
    struct shape *s;
    int (*getArea)(struct shape *s);
};

int getArea(struct shape *s)
{
    return (s->width * s->height);
}

int main()
{
    struct rectangle rect = 
    {
        .s = 
        &(struct shape){
            .width = 0,
            .height = 0,
            .setWidth = setWidth,
            .setHeight = setHeight,
        },
        .getArea = getArea,
    };

    rect.s->setWidth(&rect.s, 5);
    rect.s->setHeight(&rect.s, 7);

    printf("Total area: %d\n", rect.getArea(&rect.s));
    return 0;
}
