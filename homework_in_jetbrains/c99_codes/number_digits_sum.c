#include <stdio.h>

int main() {
    int number, sum;
    sum = 0;
    scanf("%d", &number);

    // 处理负数：取绝对值（比如-123 → 123，各位和仍为1+2+3=6）
    if (number < 0) {
        number = -number;
    }

    // 循环：只要number不为0，就提取最后一位
    while (number != 0) {
        sum += number % 10;       // 提取最后一位（%10 取余）
        number = number / 10;     // 去掉最后一位（整数除法自动截断）
    }

    printf("%d\n", sum);
    return 0;
}