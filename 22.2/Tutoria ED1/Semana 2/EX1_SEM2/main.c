#include <stdio.h>
#include "f91.h"

int main (){
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        printf("f91(%d) = %d\n", n, f91(n));
    }
    return 0;
}