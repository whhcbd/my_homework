#include <stdio.h>

long long combination (long n, long m) {
    long long upper = 1 , lower = 1;
    if (0 < n && 0 <= m && m <= n) {
        for (int i = m ; i > 0 ; i--) {
            lower *= i;
        }
        for (int i = n ; i > n - m  ; i--) {
            upper *= i;
        }
        return upper/lower;
    }else {
        if (0 == n && 0 <= m && m <=n){
            return 0;
        }
        return -1;
    }
}

int  main(void) {
    long long  n , j ;
    scanf("%lld",&n);
    n--;
    j = n;
    for ( n ;n>=0;n--) {
        for (int m = j ;m > n; m -- ) {
            printf(" ");
        }
        for (long long i = 0 ; i < n ; i++ ) {
            long long result = combination( n , i);
            printf("%lld ",result);
        }printf("1\n");
    }
}