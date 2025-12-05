#include <stdio.h>

int main(void) {    long total;
    int currentnum = 0 ,c ;
    while ((c = getchar()) != '\n' && c !=EOF) {
        if (c>='0'&&c<='9') {
            currentnum = currentnum*10+(c-'0');
        }else {
            total += currentnum;
            currentnum = 0;
        }
    }
    total += currentnum;
    printf("%ld\n",total);
}
/*描述
输入一串字符，由数字和字母组成，请截取其内部所有数字
并相加输出。如输入为sdfns92sdgs8934nsd8234c2df9
则其内部数字为92，8934，8234，2和9，相加结果为17271。
输入描述
一串字符，由字母数字组成，换行结束
输出描述
一个整数*/