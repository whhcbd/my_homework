#include <stdio.h>

int palindrome(char n[]) {
    int len=0,i=0,count=0;
    while (n[i]!='\0') {
        len++;i++;
    }i=0;
    for (int m =len/2;m>0;m--) {
        if (n[i]==n[len-1-i])
            count++;
    }if (count==len/2)
        return 1;
    else
        return 0;
}

int main(void) {
    char n[100];
    scanf("%s",&n);
    if (palindrome(n))
        printf("Yes");
    else
        printf("No");
}
/*读入一个int整数，判断其是不是回文数
输出Yes或No。如12321，4554这类数字就是回文数
输入描述
一个int整数
输出描述
Yes或No*/