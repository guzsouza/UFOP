#include "r9.h"

int soma_r9(int n){
    
    if (n == 0) 
        return 0;
    else 
        return n % 10 + soma_r9(n / 10);   
}