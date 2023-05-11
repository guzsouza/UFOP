#include <stdio.h>
#include <stdlib.h>


void sum(int *vet1, int *vet2){
    vet2[0] = (vet1[0] * vet1[3]) + (vet1[1] * vet1[2]);
    vet2[1] = vet1[1] * vet1[3];
}

void subtraction(int *vet1, int *vet2){
    vet2[0] = (vet1[0] * vet1[3]) - (vet1[1] * vet1[2]);
    vet2[1] = vet1[1] * vet1[3];
}

void plus(int *vet1, int *vet2){
    vet2[0] = (vet1[0] * vet1[2]);
    vet2[1] = (vet1[1] * vet1[3]);
}

void division(int *vet1, int *vet2){
    vet2[0] = (vet1[0] * vet1[3]);
    vet2[1] = (vet1[1] * vet1[2]);
}

void simplification(int *vet2){
    for (int i=1; i<= abs(vet2[0]); i++){
        
        if (vet2[0] %i == 0 && vet2[1] %i == 0){
            vet2[2] = vet2[0]/i;
            vet2[3] = vet2[1]/i;
        }

    }
}

int main (){

    char barra1, barra2, op;
    int *fraction, *r, n = 0; 

    fraction = (int*) malloc (sizeof(int)*4);
    r = (int*) malloc (sizeof(int)*4);
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d %c %d %c %d %c %d", &fraction[0], &barra1, &fraction[1], &op, &fraction[2], &barra2, &fraction[3]);

        if(op == '+'){
            sum(fraction, r);

        } else if (op == '-'){
            subtraction(fraction, r);
            
        }else if (op == '*'){
            plus(fraction, r);
            //atribuir o resultado

        } else
            division(fraction, r);

        simplification (r);
        printf("%d/%d = %d/%d\n", r[0], r[1], r[2], r[3]);
    }

    free(fraction);
    free(r);
}