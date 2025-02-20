#include <stdio.h>

// get_ad() 为获取模拟量的函数

/*
    1. 算术平均滤波法

    方法：
    连续取N个采样值进行算术平均运算：
    N值较大时：信号平滑度较高，但灵敏度较低
    N值较小时：信号平滑度较低，但灵敏度较高
    N值的选取：一般流量，N=12；压力：N=4

    优点：
    适用于对一般具有随机干扰的信号进行滤波；
    这种信号的特点是有一个平均值，信号在某一数值范围附近上下波动。

    缺点：
    对于测量速度较慢或要求数据计算速度较快的实时控制不适用；
    比较浪费RAM。
*/

#define N 12

char AverageValueFiter()
{
    int sum = 0;
    for(int count = 0; count < N; count++)
    {
        sum += get_ad();
        delay();
    }

    return (char)(sum / N);
}

/*
    2. 一阶滞后滤波法

    方法：
    取a=0~1
    本次滤波结果=（1-a）* 上次采样值 + a * 本次滤波结果

    优点：
    对周期性干扰具有良好的抑制作用；
    适用于波动频率较高的场合；

    缺点：
    相位滞后，灵敏度低；
    滞后程度取决于a值大小；
    不能消除滤波频率高于采样频率1/2的干扰信号
    滤波系数越小，滤波结果越平稳，但是灵敏度越低；
    滤波系数越大，灵敏度越高，但是滤波结果越不稳定。
    小数舍弃带来的误差
*/

#define a 128

char value;
char OneFactorialFilter()
{
    char new_value;
    char Return_value;
    new_value = get_ad();
    Return_value = a * value + (256 - a) * new_value;
    Return_value /= 255;
    return Return_value;
}

/*
    3. 限幅滤波法

    方法：
    根据经验确定两次采样允许的最大偏差值（设为A）
    每次采样得到新值时判断：
    如果本次值与上次值之差<=A，则本次值有效；
    如果本次值与上次值之差>A，则本次值无效，放弃本次值，用上次值代替本次值。

    优点：
    能有效克服因偶然因素引起的脉冲干扰；
    能有效克服因偶然因素引起的无法抑制的干扰；
    平滑度高，适于高频振荡的系统。

    缺点：
    无法抑制那种周期性的干扰；
    平滑度差；
*/

/*
    A值可根据实际情况调整，
    value为有效值，new_value为当前采样值，
    滤波程序返回有效的实际值。
*/

#define A 10

char value;
char AmplitudeLimitereFiter()
{
    char new_value;
    new_value = get_ad();
    if((new_value - value) >= A || (value - new_value) >= A)
        return value;
    else
        return new_value;
}

/*
    4. 中位值滤波法

    方法：
    连续采样N次（N取奇数）
    把N次采样值按大小排列
    取中间值为本次有效值

    优点：
    能有效克服因偶然因素引起的波动干扰；
    对温度、液位的变化缓慢的被测参数有良好的滤波效果。

    缺点：
    对流量、速度等快速变化的参数不宜。
*/

// N值可根据实际情况调整 排序采用冒泡法

#define N 11

char MiddleValueFiter()
{
    char value_buf[N];
    char temp;
    int i, j;
    char count;
    for(count = 0; count < N; count++)
    {
        value_buf[count] = get_ad();
        delay();
    }

    for(j = 0; j < (N - 1); j++)
    {
        for(i = 0; i < (N - j - 1); i++)
        {
            if(value_buf[i] > value_buf[i + 1])
            {
                temp = value_buf[i];
                value_buf[i] = value_buf[i + 1];
                value_buf[i + 1] = temp;
            }
        }
    }
    return value_buf[(N - 1) / 2];
}

/*
    5. 递推平均滤波法（又称滑动平均滤波法）

    方法：
    把连续取N个采样值看成一个队列
    队列的长度固定为N
    每次采样到一个新数据放入队尾，并扔掉原来队首的一次数据.(先进先出原则)
    把队列中的N个数据进行算术平均运算，就可获得新的滤波结果
    N值的选取：流量，N=12；压力：N=4；液面，N=4~12；温度，N=1~4

    优点：
    对周期性干扰具有良好的抑制作用；
    适用于高频振荡的系统。

    缺点：
    灵敏度低；
    对偶然出现的脉冲性干扰的抑制作用较差；
    不易消除由于脉冲干扰所引起的采样值偏差；
    不适用于脉冲干扰比较严重的场合；
    比较浪费RAM。
*/

#define N 12

char value_buf[N];
char i = 0;
char GlideAveeragaValueFiter()
{
    char i;
    int sum = 0;
    value_buf[N] = get_ad();
    for(i = 0; i < N; i++)
    {
        value_buf[i] = value_buf[i + 1];
        sum += value_buf[i];
    }

    return (char)(sum / N);
}

/*
    6. 加权递推平均滤波法

    方法：
    是对递推平均滤波法的改进，即不同时刻的数据加以不同的权；
    通常是，越接近现时刻的数据，权取得越大。
    给予新采样值的权系数越大，则灵敏度越高，但信号平滑度越低。

    优点：
    适用于有较大纯滞后时间常数的对象；
    不同时刻的数据加以不同的权；
    适用于波动频率较高的场合。

    缺点：
    对于纯滞后时间常数较小，采样周期较长，变化缓慢的信号；
    不能迅速反应系统当前所受干扰的严重程度，滤波效果差。
*/

// coe数组为加权系数表，存在程序存储区

#define N 12

const char coe[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const char sum_coe = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12;
char filter()
{
    char count;
    char value_buf[N];
    int sum = 0;
    value_buf[N] = get_ad();
    for(count = 0; count < N; count++)
    {
        value_buf[count] = value_buf[count + 1];
        sum += value_buf[count] * coe[count];
    }

    return (char)(sum / sum_coe);
}

/*
    7. 消抖滤波法

    方法：
    设置一个滤波计数器
    将每次采样值与当前有效值比较：
    如果采样值＝当前有效值，则计数器清零；
    如果采样值<>当前有效值，则计数器+1，并判断计数器是否>=上限N(溢出)；
    如果计数器溢出，则将本次值替换当前有效值，并清计数器。

    优点：
    对于变化缓慢的被测参数有较好的滤波效果；
    可避免在临界值附近控制器的反复开/关跳动或显示器上数值抖动。

    缺点：
    对于快速变化的参数不宜；
    如果在计数器溢出的那一次采样到的值恰好是干扰值,则会将干扰值当作有效值导入系统。
*/

#define N 12

char filter()
{
    char count = 0;
    char new_value;
    char value;
    new_value = get_ad();
    if(value == new_value)
    {
        count = 0;
    }
    else
    {
        count++;
        if(count >= N)
        {
            count = 0;
            value = new_value;
        }
    }

    return value;
}

/*
    8. 中位值平均滤波法

    方法：
    相当于“中位值滤波法”+“算术平均滤波法”
    连续采样N个数据，去掉一个最大值和一个最小值；
    然后计算N-2个数据的算术平均值；
    N值的选取：3~14。

    优点：
    融合了两种滤波法的优点；
    对于偶然出现的脉冲性干扰，可消除由于脉冲干扰所引起的采样值偏差。

    缺点：
    测量速度较慢，和算术平均滤波法一样；
    比较浪费RAM。
*/

#define N 12

char MiddleAverageValueFiter()
{
    char count;
    char i, j;
    char value_buf[N];
    int sum = 0;
    for(count = 0; count < N; count++)
    {
        value_buf[count] = get_ad();
        delay();
    }

    for(j = 0; j < (N - 1); j++)
    {
        for(i = 0; i < (N - j - 1); i++)
        {
            if(value_buf[i] > value_buf[i + 1])
            {
                char temp = value_buf[i];
                value_buf[i] = value_buf[i + 1];
                value_buf[i + 1] = temp;
            }
        }
    }
    for(count = 1; count < (N - 1); count++)
    {
        sum += value_buf[count];
    }

    return (char)(sum / (N - 2));
}

/*
    9. 限幅平均滤波法

    方法：
    相当于“限幅滤波法”+“递推平均滤波法”；
    每次采样到的新数据先进行限幅处理，
    再送入队列进行递推平均滤波处理。

    优点：
    融合了两种滤波法的优点；
    对于偶然出现的脉冲性干扰，可消除由于脉冲干扰所引起的采样值偏差。

    缺点：
    比较浪费RAM。
*/

/*
    10. 限幅消抖滤波法

    方法：
    相当于“限幅滤波法”+“消抖滤波法”；
    先限幅，后消抖。

    优点：
    继承了“限幅”和“消抖”的优点；
    改进了“消抖滤波法”中的某些缺陷，避免将干扰值导入系统。

    缺点：
    对于快速变化的参数不宜。
*/

/*
    数字滤波器与模拟滤波器的区别

    1. 工作方式不同：
    数字滤波器是通过数字运算器件对输入的数字信号进行运算和处理，从而实现设计要求的特性
    模拟滤波器完全依靠电阻器，电容器，晶体管等电子元件组成的物理网络实现滤波

    2. 数字滤波器没有模拟滤波器快

    3. 按照数字滤波器的特性，它可以被分为线性与非线性，因果与非因果，无限脉冲响应与有限脉冲响应等。其中线性时不变的数字滤波器是最基本的类型；而由于数字系统可以对延时器加以利用，因此可以引入一定程度的非因果性，获得比传统的因果滤波器更灵活强大的特性；相对于IIR滤波器，FIR滤波器有着易于实现和系统绝对稳定的优势，因此得到广泛的应用；对于时变系统滤波器的研究则导致了以卡尔曼滤波为代表的自适应滤波理论

    数字滤波器特性：
    1. 数字滤波器比模拟滤波器更高的精度，甚至能够实现后者在理论上也无法达到的性能
    2. 数字滤波器相比模拟滤波器有更高的信噪比
    3. 根据奈奎斯特采样定理，数字滤波器的处理能力受到系统采样频率的限制

    数字滤波器的工作原理：选取合适的H(ejw)，使滤波器的输出X(ejw)H(ejw)符合我们的要求，这就是数字滤波器的工作原理

    FIR滤波器：
    直接型结构；
    级联型结构；
    快速卷积型结构；
    线性相位型结构；
    频率抽样型结构；

    FIR滤波：
    即有限脉冲响应滤波，它的基本算法是一种乘法累加运行
    其表达式为：
    y[n] = b[0] * x[n] + b[1] * x[n - 1] + b[2] * x[n - 2] + ... + b[numTaps - 1] * x[n - numTaps + 1]
*/


