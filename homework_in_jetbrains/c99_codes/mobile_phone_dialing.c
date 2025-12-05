#include <stdio.h>

void print_num(char c) {
    switch (c) {
        case 'A':
        case 'B':
        case 'C':
            printf("2");
            break;
        case 'D':
        case 'E':
        case 'F':
            printf("3");
            break;
        case 'G':
        case 'H':
        case 'I':
            printf("4");
            break;
        case 'J':
        case 'K':
        case 'L':
            printf("5");
            break;
        case 'M':
        case 'N':
        case 'O':
            printf("6");
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            printf("7");
            break;
        case 'T':
        case 'U':
        case 'V':
            printf("8");
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            printf("9");
            break;
        default:
            break;
    }
}

int main() {
    char c;
    while ((c=getchar())!=EOF && c != '\n') {
        if (c>='a' && c<='z')
            c -=  ('a'-'A');
        print_num(c);
    }
    printf("\n");
    return 0;
}
/*描述

按照手机拨号盘中的数字与字母之间的对应关系把字母改变成对应的数字。输入一行英文字母(长度至少为8，但不超80)，输出一行对应的电话号码。例子：
universe -------> 86483773
MICROSOFT -------> 642767638
*/