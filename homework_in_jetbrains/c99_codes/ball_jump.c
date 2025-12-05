#include <stdio.h>

int main() {
    long double total_distance;  // 总路程
    long double current_height;  // 当前高度（用于计算弹起/下落）
    int h;
    scanf("%d", &h);

    // 初始化：第一次落地前，只下落初始高度h，总路程先加h
    total_distance = h;
    current_height = h;  // 初始高度是h，第一次落地后弹起高度为h/2

    // 第1次落地 → 第10次落地：共9次弹起+下落（每次落地后弹起再下落）
    for (int i = 1; i < 10; i++) {
        current_height /= 2;  // 本次弹起的高度（上一次落地后的反弹高度）
        total_distance += current_height * 2;  // 弹起+下落，路程加2倍弹起高度
    }

    // 第10次反弹高度：第10次落地后弹起，再减半1次（共10次减半）
    current_height /= 2;

    // 按题目示例格式输出，控制小数精度
    printf("%Lf\n", total_distance);  // 匹配示例输出59.9219（保留5位小数）
    printf("%Lf\n", current_height);  // 匹配示例输出0.0195312（保留6位小数）
    return 0;
}