#include <stdio.h>
#include <stdlib.h>

int main () {
    int n , m ;
    scanf("%d %d",&n,&m );
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++) {
            int distance = abs (i - j) ;
            printf("%c",'A' + distance);
        }
        printf("\n");
    }
}
/*在Windows的控制台环境中，所有的字符都是等宽的，默认情况下窗口中每行有 80 个字符，每个屏幕有 25 行，组成了一个字符矩阵。
利用控制台的这个特点，我们可以在控制台上绘制简单的图形。下面给出了一个 5×7 的图形的例子：
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
找出这个图形的特点，绘制一个 n×m 的图形。
输入包含两个数 n,m，用一个空格分隔。
输出与上图类似的一个 n×m 的图形      */