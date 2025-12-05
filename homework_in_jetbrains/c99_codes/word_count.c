#include <stdio.h>
#include <string.h>

int main() {
    char string[81];  // 存储输入字符串（预留\0位置）
    int word_count = 0;  // 统计单词个数
    int i = 0;

    // 1. 正确读取包含空格的字符串（用fgets替代scanf）
    fgets(string, 81, stdin);  // 读取整行，包括空格，最多80个字符
    // 处理fgets读取到的换行符（替换为字符串结束符\0）
    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    // 2. 统计单词数（单词之间用1个空格隔开，按题目要求）
    // 跳过字符串开头的空格（如果有的话）
    while (string[i] == ' ') {
        i++;
    }
    // 如果字符串非空，至少有1个单词
    if (string[i] != '\0') {
        word_count = 1;
    }
    // 遍历字符串，遇到“空格+非空格”的组合，说明是新单词
    while (string[i] != '\0') {
        // 单词之间只有1个空格，无需处理多个空格（题目明确要求）
        if (string[i] == ' ' && string[i + 1] != '\0') {
            word_count++;
        }
        i++;
    }

    // 3. 输出单词数（格式符%d对应int类型）
    printf("%d\n", word_count);
    return 0;
}