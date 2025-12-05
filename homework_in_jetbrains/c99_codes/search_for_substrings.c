#include <stdio.h>
#include <string.h>

int main() {
    char str[81], substr[81];
    fgets(str, sizeof(str), stdin);
    fgets(substr, sizeof(substr), stdin);

    str[strcspn(str, "\n")] = '\0';
    substr[strcspn(substr, "\n")] = '\0';

    int count = 0;                    // 初始化计数为0
    int position[81] = {0};           // 标记匹配的起始位置（0=未匹配，1=匹配）
    int len_str = strlen(str);        // 长串长度
    int len_sub = strlen(substr);     // 子串长度

    // 边界条件：子串为空或子串比长串长，直接输出0
    if (len_sub == 0 || len_sub > len_str) {
        printf("0\n");
        return 0;
    }

    // 遍历所有可能的起始位置（i最大为 len_str - len_sub）
    for (int i = 0; i <= len_str - len_sub; i++) {
        // 从str[i]开始，与substr比较前len_sub个字符，相等则计数并标记位置
        if (strncmp(&str[i], substr, len_sub) == 0) {
            count++;
            position[i] = 1;  // 标记该起始位置（0-based）匹配
        }
    }

    // 输出出现次数
    printf("%d\n", count);

    // 输出匹配位置（转换为1-based，空格分隔）
    for (int i = 0; i <= len_str - len_sub; i++) {
        if (position[i] == 1) {
            printf("%d ", i + 1);  // 题目要求位置从1开始计数
        }
    }
    // 去掉最后一个多余的空格（优化输出格式）
    if (count > 0) {
        printf("\b");  // 退格符删除最后一个空格
    }
    printf("\n");

    return 0;
}

//可以使用strncmp(&s1[i], s2, n)，控制从s1的第i个元素开始，与s2进行比较

/*
描述
用户从键盘任意输入一句话（不超过80字符），以及感兴趣的子串。要求写程序分析子串在句子中出现的位置和次数。
e.g：Helen and her husband went to Ireland. 子串: and
则输出：and出现了3次，位置为：6 18 34
输入为两行，第一行为长字符串，第二行为子串。两者都可能包含空格。
输出为两行，第一行为出现次数，第二行为出现的位置，空格分隔，从小到大排列

用例输出 1
3
6 18 34
*/