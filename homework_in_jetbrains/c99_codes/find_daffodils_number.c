#include <stdio.h>

int main(void) {
    for (int i= 100;i<1000;i++) {
        int A = i/100 , B ,C;
        B =( i - 100*A )/10;
        C = i - 100*A-10*B;
        if (i==A*A*A+B*B*B+C*C*C) {
            printf("%6d",i);
        }
    }
}
/*描述
若三位数ABC，ABC=A*A*A+B*B*B+C*C*C，则称ABC为水仙花数。
输出描述
按从小到大输出所有水仙花数，每个数占6个字符宽度*/