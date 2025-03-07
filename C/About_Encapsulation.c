#include <stdio.h>
#include <string.h>

struct person
{
    char name[12];
    int age;
    void (*get_name)(struct person *p, char *name);
    void (*get_age)(struct person *p, int age);
};

static void get_name(struct person *p, char *name)
{
    strcpy(p->name, name);
}

static void get_age(struct person *p, int *age)
{
    *age = p->age;
}

static struct person p1 = 
{
    .name = "xiaohua",
    .age = 21,
    .get_age = get_age,
    .get_name = get_name,
};

int main()
{
    char name[12] = {0};
    int age = 0;
    struct person *p = &p1;

    p->get_age(p, &age);
    p->get_name(p, name);

    printf("name = %s, age = %d\n", name, age);

    return 0;

}

