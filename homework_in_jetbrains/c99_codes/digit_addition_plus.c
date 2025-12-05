#include <stdio.h>

int main() {
    int number, sum;
    sum = 0;
    scanf("%d", &number);
    if (number < 0) {
        number = -number;
    }
    digit_addition:
    while (number != 0) {
        sum += number % 10;       // 提取最后一位（%10 取余）
        number = number / 10;     // 去掉最后一位（整数除法自动截断）
    }
    if (sum > 9) {
        number = sum;
        sum = 0;
        goto digit_addition;
    }
    printf("%d\n", sum);
    return 0;
}
/*描述
输入一个整数，将其各位数相加，得到结果后重复进行位数相加，
直到其变成一个个位数，输出该个位数，如6456，
第一次位数相加结果为6+4+5+6=21，不是个位数，则需要再进行一次相加，
得到2+1=3*/