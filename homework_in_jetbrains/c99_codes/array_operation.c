#include <stdio.h>

double element(double i) {
    double a = 1/(i*(i+1)*(i+2));
    return a;
}

int main() {
    double array[100];
    for(int i = 1 ; i < 101; i++)
        array[i-1]=element(2.0*i);
    double result = 0;
    for (int i = 0 ; i <99;i=i+2)
        result = result+array[i]-array[i+1];
    result*=4.0;
    result+=3.0;
    printf("%.4lf",result);
    return 0;
}


/*描述
定义一个数组，包含100个double类型元素。编写一个循环，将以下数字存入数组。
1/(2*3*4), 1/(4*5*6), 1/(6*7*8), …, 1/(200*201*202）
随后再进行一次循环，计算
data[0] - data[1] + data[2] - data[3] … - data[99]
将得到的结果乘以4.0，加3.0，输出最终结果
输入描述
无
输出描述
一个数字，保留4位小数*/