#include <stdio.h>

int main()
{
    char board[10][11]; // 10行，每行最多10个有效字符 + 1个字符串结束符'\0'

    // 提示用户输入
    printf("请输入10行内容(每行最多10个字符:)\n");

    // 使用 fgets 读取并处理换行符
    for (int i = 0; i < 10; i++)
    {
        printf("第%d行:", i + 1);
        if (fgets(board[i], sizeof(board[i]), stdin) == NULL)
        {
            // 处理输入错误
            printf("输入错误！\n");
            return 1;
        }

        // 移除换行符（fgets会读取换行符，替换为字符串终止符）
        for (int j = 0; j < 11; j++)
        {
            if (board[i][j] == '\n')
            {
                board[i][j] = '\0';
                break;
            }
        }
    }

    // 输出数组内容
    printf("\n你输入的内容如下:\n");
    for (int i = 0; i < 10; i++)
    {
        // 两种输出方式可选，效果一致：
        // 方式1：使用printf打印字符串
        printf("第%d行:%s\n", i + 1, board[i]);

        // 方式2：使用puts打印（自动换行，无需加\n）
        // puts(board[i]);
    }

    return 0;
}