#include <iostream>
#include <cstring>

struct Vector3
{
    /* data */
    float x, y, z;
};


int main()
{
    // ��ջ�Ϸ����ڴ�
    int value = 5;
    int array[5];

    for(int i = 0; i < 5; i++)
    {
        array[i] = i;
    }

    // �ڶ��Ϸ����ڴ�
    int* hvalue = new int;
    *hvalue = 5;
    int* harray = new int[5];

    for(int i = 0; i < 5; i++)
    {
        harray[i] = i;
    }

    delete hvalue;
    delete[] harray;

    std::cin.get();
}
