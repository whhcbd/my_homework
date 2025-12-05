#include <stdio.h>
#include <string.h>

int main() {

    char a[1001], b[1001];
    // 读取输入（%s自动忽略换行符，适配两行输入）
    scanf("%s", a);
    scanf("%s", b);

    int lenA = strlen(a);  // 字符串a的长度
    int lenB = strlen(b);  // 字符串b的长度
    int i = lenA - 1;      // 指向a的末尾（最低位）
    int j = lenB - 1;      // 指向b的末尾（最低位）
    int carry = 0;         // 进位标志
    int k = 0;             // 结果数组的索引
    int res[1002] = {0};   // 存储相加结果（最多1001位，初始化全0）

    // 循环条件：任一字符串未处理完 或 仍有进位
    while (i >= 0 || j >= 0 || carry > 0) {

        int digitA = (i >= 0) ? (a[i] - '0') : 0;
        int digitB = (j >= 0) ? (b[j] - '0') : 0;

        int sum = digitA + digitB + carry;  // 当前位总和
        res[k++] = sum % 10;                // 存储当前位结果
        carry = sum / 10;                   // 更新进位

        i--;
        j--;
    }


    for (int m = k - 1; m >= 0; m--) {
        printf("%d", res[m]);
    }
    printf("\n");

    return 0;
}