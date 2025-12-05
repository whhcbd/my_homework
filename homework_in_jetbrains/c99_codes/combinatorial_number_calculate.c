#include <stdio.h>

int main () {
    long long n , m , upper , lower;
    lower = 1 ;
    upper = 1 ;
    scanf("%d  %d", &n, &m);
    if (0 < n && 0 <= m && m <= n) {
        for (int i = m ; i > 0 ; i--) {
            lower *= i;
        }
        for (int i = n ; i > n - m  ; i--) {
            upper *= i;
        }
        printf("%d", upper/lower);
    }else {
        printf("0");
    }
    return 0;
}