#include "r9.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long long int n;
    while (scanf("%lld", &n), n) {
        int sum = soma_r9(n);
        if (sum % 9 == 0) {
            printf("%lld is a multiple of 9\n", n);
        } else {
            printf("%lld is not a multiple of 9\n", n);
        }
    }
    return 0;
}