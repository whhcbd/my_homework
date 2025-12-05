#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i++) {
        for (int j= 1 ; j <=i;j++) {
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
}
/*描述
输出 N*N 乘法口诀表。
输入描述
请输入整数N。
输出描述
输出NN乘法表，每行两个式子之间用一个空格分隔，每行后有一个空格。*/