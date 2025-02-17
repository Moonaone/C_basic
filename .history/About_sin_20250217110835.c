#include <math.h>
#include <stdio.h>

#define PointMax 64
#define PI 3.1415926
unsigned int sinDate[PointMax] = {0};

// point 一个周期内的采样点数
// 生成一个周期内的正弦波数据 水平线为32 最大值为64 最小值为0
void get_sin_tab1(unsigned int point)
{
    unsigned int i = 0, j = 0;
    float hd = 0.0; // 弧度
    float fz = 0.0; // 峰值
    unsigned int tem = 0;
    j = point / 2;
    hd = PI / j;
    for(i = 0; i < point; i++)
    {
        fz = j * sin(hd * i) + j;
        tem = (unsigned int)fz;
        sinDate[i] = tem;
        printf("%d,", tem);
    }
    printf("\r\n");
}

// 可设置点数与最大值
void get_sin_tab2(int point, unsigned int maxnum)
{
    unsigned int i = 0, j = 0, k = 0;
    float hd = 0.0; // 弧度
    float fz = 0.0; // 峰值
    unsigned int tem = 0;
    j = point / 2;
    hd = PI / j;
    k = maxnum / 2;
    for(i = 0; i < point; i++)
    {
        fz = k * sin(hd * i) + k;
        tem = (unsigned int)(fz * 1.0);
        sinDate[i] = tem;
        printf("%d,", tem);
    }
}

int main()
{
//    get_sin_tab1(PointMax);
    get_sin_tab2(64, 800);

    return 0;
}
