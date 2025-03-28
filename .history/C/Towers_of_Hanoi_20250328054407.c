/*
    河内之塔(Towers of Hanoi)是法国人M.Claus(Lucas)于1883年从泰国带至法国的，河内为越战时
北越的首都，即现在的胡志明市；1883年法国数学家 Edouard Lucas曾提及这个故事，据说创世
纪时Benares有一座波罗教塔，是由三支钻石棒（Pag）所支撑，开始时神在第一根棒上放置64
个由上至下依由小至大排列的金盘（Disc），并命令僧侣将所有的金盘从第一根石棒移至第三根
石棒，且搬运过程中遵守大盘子在小盘子之下的原则，若每日仅搬一个盘子，则当盘子全数搬
运完毕之时，此塔将毁损，而也就是世界末日来临之时。
*/


#include <stdio.h>

void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        printf("Move sheet %d from %c to %c\n", n, A, C);
    }
    else
    {
        hanoi(n-1, A, C, B);
        printf("Move sheet %d from %c to %c\n", n, A, C);
        hanoi(n-1, B, A, C);
    }
}

int main()
{
    int n;
    printf("Please input the number of sheets: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0; 
}
