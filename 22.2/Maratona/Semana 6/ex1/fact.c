#include <stdio.h>

long long int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        long long int soma = fatorial(m) + fatorial(n);
        printf("%lld\n", soma);
    }
    return 0;
}