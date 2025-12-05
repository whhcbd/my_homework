#include <stdio.h>

int gcd(int a ,int b) {
    int r = a % b ;
    while (r != 0) {
        a = b ; b = r ;
        r = a % b;
    }
    return b;
}

int main(void) {
    int n ,x , y ;
    scanf("%d",&n);
    for (;n>0;n--){
        scanf("%d %d",&x,&y);
        printf("%d\n",gcd(x,y));
    }
}

// Created by 16244 on 2025/11/12.
/*蒜头君被一个问题给难住了，现在需要你帮帮忙。问题是：给出两个正整数，求出它们的最大公约数
输入描述
第一行输入一个整数 n(0<n≤100)，表示有 n 组测试数据；
随后的 n 行输入两个整数 x,y(0<x,y≤10000)。
输出描述
输出每组测试数据的最大公约数。*/