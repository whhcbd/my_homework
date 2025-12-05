#include <stdio.h>

int A[101][101];

void trans(int n,int i) {
    for
}

int main() {
    int n, m,temp;
    scanf("%d %d",&n,&m);
    for (int i = 1 ; i<=n;i++) {
        for (int j = 1 ;j<=m;j++)
            scanf("%d",&A[i][j]);
    }
    for (int i=0;i<m;i++) {

    }
}
/*
描述
输入一个n行m列的矩阵A，输出它的转置A T

输入描述
第一行包含两个整数n和m，表示矩阵A的行数和列数。1 <= n <= 100，1 <= m <= 100。
接下来n行，每行m个整数，表示矩阵A的元素。相邻两个整数之间用单个空格隔开，每个元素均在1~1000之间。

输出描述
m行，每行n个整数，为矩阵A的转置。相邻两个整数之间用单个空格隔开。*/