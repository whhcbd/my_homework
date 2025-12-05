#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    char symbol;
    scanf("%d %c", &N, &symbol);
    int k = 0;
    while (2 * (k + 1) * (k + 1) - 1 <= N) {
        k++;
    }
    int total_used = 2 * k * k - 1;
    int rows = 2 * k - 1;
    int mid = k - 1;    for (int i = 0; i < rows; i++) {
        int d = abs(i - mid);
        int spaces = k - d - 1;
        for (int s = 0; s < spaces; s++) {
            printf(" ");
        }
        int stars = 2 * d + 1;
        for (int c = 0; c < stars; c++) {
            printf("%c", symbol);
        }

        printf("\n");
    }
    printf("%d\n", N - total_used);
    return 0;
}
