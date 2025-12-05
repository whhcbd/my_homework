#include <stdio.h>

void change_position(int index,int num,int array[],int total) {
    for (int i=total;i>index;i-- )
        array[i]=array[i-1];
    array[index]=num;
}

int main() {
    int array[201],n,k,index,num;
    scanf("%d",&n);
    for (int i = 0 ; i<n;i++)
        scanf("%d",&array[i]);
    scanf("%d",&k);
    for (int i = 0 ; i<k;i++) {
        scanf("%d %d",&index,&num);
        change_position(index,num,array,n+i+1);
    }for (int i = 0 ; i <n+k;i++)
        printf("%d ",array[i]);
}

/*描述
给定一个整型数组，共n个数字，n<100。根据操作在对应位置插入数字，最后输出数组。保证最终数组大小不超过200。
输入描述如下
第一行输入一个整数n，代表数组最初有n个数字。
第二行n个数字，代表数组初始的n个数字。
第三行输入一个整数k，代表共k个操作，随后k行每行代表一个操作，所有操作结束后，输出结果。
对于每个操作，共有两个数字，index和num，代表在数组下标为index的位置插入数字num。
输出一行，逐个打印数组内元素，空格分隔。

用例输入
5
1 2 3 4 5
2
2 666
0 777
用例输出
777 1 2 666 3 4 5
*/