#include <stdio.h>

// 11行5列数组，存储每行的num、1/num、num²、num³、num⁴
double array[11][5];

int main() {
    double x;
    scanf("%lf", &x);

    // 第一步：初始化第一列（num = x + 0.1*i，i从0到10）
    for (int i = 0; i < 11; i++) {
        array[i][0] = x + 0.1 * i;
    }

    // 第二步：每行基于自身第一列的num，计算后续4列
    for (int i = 0; i < 11; i++) {
        double num = array[i][0];  // 当前行的第一列数值
        array[i][1] = 1.0 / num;   // 1/num
        array[i][2] = num * num;   // num²
        array[i][3] = num * num * num;  // num³
        array[i][4] = num * num * num * num;  // num⁴
    }

    // 第三步：按要求输出（左对齐10位宽，保留4位小数）
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%-10.4lf", array[i][j]);
        }
        printf("\n");  // 每行结束换行
    }

    return 0;
}
/*描述
定义一个double类型数组，11行5列。读取一个浮点数x, 使用x, x+0.1, x+0.2, …, x+1.0初始化第一列。如果行中第一个元素为x，则其余元素分别是1/x, x^2, x^3, x^4。请输出数组的值
输入描述
读入一个浮点数
输出描述
输出数组，每个数字占10位宽，左对齐，保留4位小数*/