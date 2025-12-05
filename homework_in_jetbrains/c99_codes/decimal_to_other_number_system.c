#include <stdio.h>

void transform(int N, int R);

int main(void) {
    int N, R;
    scanf("%d %d", &N, &R); // 读取输入

    if (N == 0) {
        printf("0"); // 处理特殊情况 N=0
        return 0;
    }

    if (N < 0) {
        printf("-"); // 输出负号
        N = -N; // 转换为正数处理
    }

    transform(N, R); // 调用转换函数

    return 0;
}

void transform(int N, int R) {
    char result[32]; // 存储转换结果，32位足够
    int i = 0;

    // 不断除以R取余数
    while (N != 0) {
        int remainder = N % R;

        // 将余数转换为对应的字符
        if (remainder < 10) {
            result[i] = '0' + remainder; // 数字 0-9
        } else {
            result[i] = 'A' + (remainder - 10); // 字母 A-F
        }

        N = N / R;
        i++;
    }

    // 逆序输出结果（因为除R取余是从低位到高位）
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }
}
/*描述
输入一个十进制数 N，将它转换成 R 进制数输出。在10 ≤ R ≤ 16 的情况下，用’A’表示 10，
用’B’表示 11，用’C’表示 12，用’D’表示 13，用’E’表示 14，用’F’表示 15。
输入描述
输入包含两个整数N(N≤10000) 和 R(2≤R≤16)。
注意，N 有可能是负整数。
输出描述
输出一行，表示转换后的数。*/