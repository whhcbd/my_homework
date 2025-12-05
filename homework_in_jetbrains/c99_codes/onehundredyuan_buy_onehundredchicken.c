#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // 读取输入的正整数n
    int haveanswer = 0;
    int chicken_dad, chicken_mom, chick;

    // 公鸡x的范围：0 ~ n//7（7x ≤ n，避免无效循环）
    for (chicken_dad = 0; chicken_dad <= n / 7; chicken_dad++) {
        int temp = n - 7 * chicken_dad; // 通用方程：7x + 4y = n → 4y = n-7x
        // 验证y是非负整数（temp≥0且能被4整除）
        if (temp >= 0 && temp % 4 == 0) {
            chicken_mom = temp / 4;
            chick = n - chicken_dad - chicken_mom; // 鸡雏数量=总数量-公鸡-母鸡
            // 验证鸡雏非负且是3的倍数（满足“3只1文”的约束）
            if (chick >= 0 && chick % 3 == 0) {
                printf("%d %d %d\n", chicken_dad, chicken_mom, chick);
                haveanswer = 1;
            }
        }
    }

    // 无有效解时输出
    if (haveanswer == 0) {
        printf("No Answer.");
    }
    return 0;
}