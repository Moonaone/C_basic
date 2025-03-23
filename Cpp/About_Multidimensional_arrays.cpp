#include <iostream>
#include <vector>

int main()
{
    int* array = new int[50];
    int** a2d = new int*[50];

    for(int i = 0; i < 50; i++)
    {
        a2d[i] = new int[50];
    }

    int*** a3d = new int**[50];

    for(int i = 0; i < 50; i++)
    {
        a3d[i] = new int*[50];
        for(int j = 0; j < 50; j++)
        {
            a3d[i][j] = new int[50];
            // int** ptr = a3d[i];
            // ptr[j] = new int[50];
        }
    }



    a2d[0][0] = 0;
    a2d[0][1] = 0;
    a2d[0][2] = 0;


    delete[] array;

    for(int i = 0; i < 50; i++)
    {
        delete[] a2d[i];
    }

    delete[] a2d;

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            delete[] a3d[i][j];
        }
        delete[] a3d[i];
    }

    std::cin.get();
}


