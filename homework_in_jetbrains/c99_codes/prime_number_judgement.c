#include <stdio.h>
#include <math.h>  // 用于sqrt()函数，优化素数判断效率

// 辅助函数：判断n是否为素数，是则返回1，否则返回0
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int primes[100];
    int count = 0;   // 记录数组中素数的个数

    for (int num = 101; num < 201; num++) {
        if (isPrime(num)) {  // 判断是否为素数
            primes[count] = num;  // 存入数组
            count++;  // 素数个数+1
        }
    }
    printf("%d\n",count);
    for (int i = 0; i < count; i++)
        printf("%d ", primes[i]);

    return 0;
}
/*描述
判断101-200之间有多少个素数，并输出所有素数
输出描述
先输出一行，代表素数个数，第二行逐个输出所有素数，从小到大，空格分隔*/