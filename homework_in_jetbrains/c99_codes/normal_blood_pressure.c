#include <stdio.h>

int ifnormal(int a,int b) {
    if (b>=60&&b<=90&&a>=90&&a<=140)
        return 1;
    else
        return 0;
}

int main(void) {
    int n ,systolic_pressure ,diastolic_pressure,hours=0,longest=0;
    scanf("%d",&n);
    for (int i = n ; i>0;i--) {
        scanf("%d %d",&systolic_pressure,&diastolic_pressure);
        if (ifnormal(systolic_pressure,diastolic_pressure)){
            hours++;
        }else {
            hours=0;
        }if (hours>=longest)
            longest=hours;
    }
    printf("%d",longest);
}

/*描述
监护室每小时测量一次病人的血压，若收缩压在 90−140 之间并且舒张压在 60−90 之间（包含端点值）则称之为正常。现给出某病人若干次测量的血压值，计算病人保持正常血压的最长小时数。
输入描述
第一行为一个正整数 n，n &lt; 100；其后有 n 行，每行 2 个正整数，分别为一次测量的收缩压和舒张压（都在 [1,200] 范围内），中间以一个空格分隔。
输出描述
输出仅一行，血压连续正常的最长小时数。*/