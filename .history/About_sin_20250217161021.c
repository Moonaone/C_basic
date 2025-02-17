#include <math.h>
#include <stdio.h>

#define PointMax 64
#define PI 3.1415926
unsigned int sinDate[PointMax] = {0};

// point һ�������ڵĲ�������
// ����һ�������ڵ����Ҳ����� ˮƽ��Ϊ32 ���ֵΪ64 ��СֵΪ0
void get_sin_tab1(unsigned int point)
{
    unsigned int i = 0, j = 0;
    float hd = 0.0; // ����
    float fz = 0.0; // ��ֵ
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

// �����õ��������ֵ
void get_sin_tab2(int point, unsigned int maxnum)
{
    unsigned int i = 0, j = 0, k = 0;
    float hd = 0.0; // ����
    float fz = 0.0; // ��ֵ
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
    printf("\r\n");
}

// �ı䲨�ε���ʼ��λ
void get_sin_tab3(unsigned int point, unsigned int maxnum)
{
    unsigned int i = 0, j = 0, k = 0;
    float hd = 0.0; // ����
    float fz = 0.0; // ��ֵ
    unsigned int tem = 0;
    j = point / 2;
    hd = PI / j;
    k = maxnum / 2;
    for(i = 0; i < point; i++)
    {
        fz = k * sin(hd * (i + 180)) + k;
        tem = (unsigned int)(fz * 1.0);
        sinDate[i] = tem;
        printf("%d,", tem);
    }
    printf("\r\n");
}

// �ٴθı�
void get_sin_tab4(unsigned int point, unsigned int maxnum)
{
    unsigned int i = 0, j = 0, k = 0;
    float hd = 0.0; // ����
    float fz = 0.0; // ��ֵ
    unsigned int tem = 0;
    j = point / 2;
    hd = PI / j;
    k = maxnum / 2;
    for(i = 0; i < point; i++)
    {
        fz = k * sin(hd * (i + 270)) + k;
        tem = (unsigned int)(fz * 1.0);
        sinDate[i] = tem;
        printf("%d,", tem);
    }
    printf("\r\n");
}

int main()
{
//    get_sin_tab1(PointMax);
//    get_sin_tab2(64, 800);
//    get_sin_tab3(64, 800);
    get_sin_tab4(64, 800);

    return 0;
}
