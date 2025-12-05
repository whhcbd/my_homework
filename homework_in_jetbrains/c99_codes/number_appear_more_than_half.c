#include <stdio.h>

int array[1000],count[99]={0};

int main() {
    int n ;
    scanf("%d",&n);
    for (int i =0;i<n;i++)
        scanf("%d",&array[i]);
    for (int i = 0;i<n;i++)
        count[array[i]+49]++;
    int result=51;
    for (int i = 0;i<99;i++) {
        if (count[i]>n/2)
            result = i-49;
    }
    if (result!=51)
        printf("%d",result);
    else
        printf("no");
}
/*描述
给出一个含有 n(0 < n < 1000) 个整数的数组，请找出其中出现次数超过一半的数。
数组中的数大于 -50 且小于 50。

输入描述
第一行包含一个整数 n，表示数组大小；
第二行包含 n 个整数，分别是数组中的每个元素，相邻两个元素之间用单个空格隔开。

输出描述
如果存在这样的数，输出这个数；否则输出"no"。*/