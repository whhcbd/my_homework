#include <stdio.h>
#define arithmetic_progression 1    //等差
#define geometric_progression 0     //等比

int sequence_type(int a ,int b,int c) {
    if (a+c==2*b)
        return arithmetic_progression;
    else
        return geometric_progression;
}

int arithmetic_kth(int a,int b,int k) {
    int d = b-a;
    int kth = (a % 200907 + ( (k - 1) % 200907 ) * (d % 200907) % 200907) % 200907;
    return kth;
}

int geometric_kth(int a,int b,int k) {
    int q=b/a,kth=a%200907;
    for (int j = k-1; j>0; j--)
        kth = (kth * (q % 200907)) % 200907;
    return kth;
}

int main(void) {
    int t,a,b,c,k;
    scanf("%d",&t);
    for (t;t>0;t--) {
        scanf("%d %d %d %d",&a,&b,&c,&k);
        if (sequence_type(a,b,c))
            printf("%d\n",arithmetic_kth(a,b,k));
        else
            printf("%d\n",geometric_kth(a,b,k));
    }
}
/*描述
BSNY 在学等差数列和等比数列，当已知前三项时，就可以知道是等差数列还是等比数列。现在给你序列的前三项，这个序列要么是等差序列，要么是等比序列，你能求出第 k 项的值吗。 如果第 k 项的值太大，对 200907 取模。
输入描述
第一行一个整数 T，表示有 T 组测试数据；
对于每组测试数据，输入前三项 a,b,c，然后输入 k。1 2 3 5
输出描述
对于每组数据输出第 k 项的值，对 200907 取模。*/