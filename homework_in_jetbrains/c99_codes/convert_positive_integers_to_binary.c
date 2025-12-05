#include <stdio.h>

int convert(int a) {
    int b=0,mul=1;
    while (a!=0) {
        b= b+(a%2)*mul;
        mul*=10;
        a/=2;
    }
    return b;
}

int main(void) {
    int n;
    scanf("%d",&n);
    printf("%d",convert(n));
}
//一个正整数n，输出其相应的二进制