#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char a[50],b[50];
    scanf("%d",&n);
    getchar();
    fgets(a,sizeof(a),stdin);
    for (int i =1;i<n;i++) {
        fgets(b,sizeof(b),stdin);
        if (strcmp(a, b) > 0)
            strcpy(a, b);
    }
        printf("%s",a);
}

/*描述

读入n个字符串，找出字典序最小的字符串，注意字符串包含空格。
输入为n+1行，第一行为一个数字，代表n。
随后n行每行一个字符串。
输出一行，为字典序最小字符串

用例输入 1

3
banana split
apple pie
hello world
用例输出 1

apple pie*/