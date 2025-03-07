#include <stdio.h>
#include <string.h>

struct person
{
    char name[24];
    int age;
    void (*get_name)(struct person *p, char *name);
};

struct usa_person
{
    struct person p;
    void (*get_name)(struct usa_person *p, char *name);
};

static void get_name(struct person *p, char *name)
{
    struct usa_person *child = (struct usa_person *)p;

    child->get_name(p, name);
}

static void get_usa_name(struct person *p, char *name)
{
    sprintf(name, "%s", p->name);
    sprintf(name + strlen(p->name), "%s", "-usa");
}

static struct usa_person usa_p =
{
    .get_name = get_usa_name,
    .p.get_name = get_name,
    .p.name = "xiaohua",
};

int main()
{
    char name[24] = {0};

    struct person *p = (struct person *)&usa_p;

    p->get_name(p, name);
    printf("name = %s\n", name);

    return 0;
}

