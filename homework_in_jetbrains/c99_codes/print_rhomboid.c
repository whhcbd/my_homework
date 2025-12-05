#include<stdio.h>

int main() {
    int n;
    int v;
    scanf("%d",&n);
    v = n;
    for ( n ; n >= 1; n--) {
        int i = n -1;
        while (i >= 1) {
            printf(" ");
            i = i-1;
        }
        int j = v;
        while (j >= 1) {
            printf("A");
            j = j-1;
        }
        printf("\n");
    }
    return 0;
}

/*蒜头君非常喜欢平行四边形，现在需要打印一个 n 行的由字母 A 组成的平行四边形，我们来跟他比赛一下谁写得又快又好吧！
当 n=5 时，这个平行四边形是这样的：
    AAAAA
   AAAAA
  AAAAA
 AAAAA
AAAAA
输入描述
输入一行包含 1 个整数 n(1≤n≤100) 。
输出描述
输出 n 行，为题目要求的平行四边形
数据规模与约定
对于 100% 的数据满足 1≤n≤100*/