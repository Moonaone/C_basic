#include <stdio.h>

#define MAX_TABLE_LEN 100 // 哈希表的最大长度

void create_hash(int a[], int n, int table[])
{
    int i;
    for(i = 0; i < n; i++)
    {
        table[a[i]]++;

    }
}

int find_key(int table[], int key)
{
    return table[key] != 0;
}

// 计数排序 : 适合0~99的数字排序
void sort(int a[], int n)
{
    int table[MAX_TABLE_LEN] = {0};
    for(int i = 0; i < n; i++)
    {
        table[a[i]]++; // 记录a中每个元素出现的次数
    }
    int k = 0;
    for(int i = 0; i < MAX_TABLE_LEN; i++)
    {
        for(int j = 0; j < table[i]; j++)
        {
            a[k++] = i;
        }
    }
}

int int_func(int key)
{
    return key % MAX_TABLE_LEN;
}

int string_func(const char *key)
{
    int sum = 0;
    while(*key)
    {
        sum += *key;
        key++;
    }
    return sum % MAX_TABLE_LEN;
}

int main()
{
    int table[MAX_TABLE_LEN] = {0};

    table[int_func(523)]++;
    table[int_func(23)]++;
    table[string_func("abc")]++;
    table[string_func("cba")]++;

    printf("In hash table:\n");
    for(int i = 0; i < MAX_TABLE_LEN; i++)
    {
        if(table[i] > 0)
        {
            printf("table[%d] = %d\n", i, table[i]);
        }
    }
    return 0;
}

/*
int main()
{
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int i;
    // 设置一个长度

    int table[MAX_TABLE_LEN] = {0};
    creat_hash(a, 10, table);

    printf("In hash table:/n");

    for(i = 0; i < MAX_TABLE_LEN; i++)
    {
        if(table[i] > 0)
        {
            printf("%d apper %d times\n", i, table[i]);
        }
    }

    printf("test:\n");
    for(i = 1; i <= 10; i++)
    {
        if(find_key(table, i)) // 如果找到i
        {
            printf("%d is in array\n", i);
        }
        else
        {
            printf("%d is not in array\n");
        }
    }
    return 0;
}
*/

/*
int main()
{
    int a[] = {5, 3, 1, 7, 9, 2, 4, 6, 8, 0};   
    sort(a, 10);
    printf("Sorted array:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
*/
