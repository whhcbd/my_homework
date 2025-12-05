#include <stdio.h>

int main() {
    int n,array[110],count[101]={0};
    scanf("%d",&n);
    for (int i = 0 ;i<n;i++) {
        scanf("%d",&array[i]);
        count[array[i]+50]++;
    }for (int i = 0 ;i<101;i++) {
        if (count[i]!=0)
            printf("%d %d\n",i-50,count[i]);
    }
    return 0;
}

/*描述
读入一个数组，统计里面每个数字出现次数，并输出。
输入两行，第一行一个整数n，代表数组大小，第二个n个数字，代表数组元素。n<100, 每个元素-50到50范围内。
输出每行两个数字，第一个数字为一个数组元素，第二个为该元素在数组出现次数，请按照元素大小逐行输出
用例输入
6
5 3 10 6 3 5
用例输出
3 2
5 2
6 1
10 1*/