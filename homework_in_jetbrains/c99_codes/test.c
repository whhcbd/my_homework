#include <stdio.h>
#include <string.h>

int main() {
    char board[10][11];  // 10行，每行最多10个有效字符 + 1个'\0'
    int i;

    // 英文提示（避免编码乱码）
    printf("Please enter 10 lines (max 10 characters per line):\n");

    for (i = 0; i < 10; ) {  // 不自动i++，空行时重新读取
        printf("Line %d: ", i + 1);

        // 关键：%10[^\n] 表示读取最多10个字符，直到遇到换行符（含空格）
        int ret = scanf("%10[^\n]", board[i]);

        // 处理输入结果
        if (ret == EOF) {  // 输入错误（如Ctrl+Z/C）
            printf("Input error!\n");
            return 1;
        } else if (ret == 0) {  // 空行（直接按回车，未读取到任何字符）
            getchar();  // 清除缓冲区中残留的换行符
            printf("Empty line is not allowed. Please re-enter.\n");
            continue;  // 重新读取当前行
        } else {  // 成功读取一行（含非空字符）
            // 清除缓冲区残留字符（处理输入超过10个字符的情况）
            while (getchar() != '\n');
            i++;  // 有效输入，推进到下一行
        }
    }

    // 输出结果
    printf("\nYour input is as follows:\n");
    for (i = 0; i < 10; i++) {
        printf("Line %d: %s\n", i + 1, board[i]);
    }

    return 0;
}