#include <stdio.h>

long double factorial(int i ) {
    long long factorial = 1;
    if (i!=0) {
        for (i;i>0;i--)
            factorial *= i;
    }
    return factorial;
}

int main(void) {
    long double e=0,E = 1 ;
    int i = 0;
    while (E >= 0.000001) {
        E = factorial(i);
        e += (1/E);
        i++;
    }
    printf("%.6Lf",e);
}
//求e值。 E约等于1/0!+1/1!+1/2!+….+E(E<10的-6次方)

