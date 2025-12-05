#include <stdio.h>

int main() {
    char n[1000];
    int m;
    scanf("%s %d", n, &m);
    int len = 0;
    while (n[len] != '\0') {
        len++;
    }
    m = m % len;
    char result[1000];
    if (m == 0) {
        for (int i = 0; i < len; i++) {
            result[i] = n[i];
        }
    } else {
        for (int i = 0; i < m; i++) {
            result[i] = n[len - m + i];
        }
        for (int i = 0; i < len - m; i++) {
            result[m + i] = n[i];
        }
    }
    result[len] = '\0';
    int start = 0;
    while (start < len - 1 && result[start] == '0') {
        start++;
    }
    printf("%d ", len);
    for (int i = start; i < len; i++) {
        printf("%c", result[i]);
    }
    printf("\n");
    return 0;
}