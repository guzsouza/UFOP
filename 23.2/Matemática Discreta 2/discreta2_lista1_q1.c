#include <stdio.h>
#include <stdbool.h>

int main(){

    int verifica = 0;
    do{
        //declaração de variáveis

        int num_dividendo = 0, num_calculo = 0, num_divisor = 0, resto = 0, quociente = 0;
        bool verificaNeg = false;

        //entrada de dados

        printf("Digite um número para ser o dividendo: \n"); scanf("%d", &num_dividendo);
        printf("Digite um número para ser o divisor: \n"); scanf("%d", &num_divisor);

        //cálculo

        if(num_dividendo < 0 && num_divisor < 0){
            num_dividendo *= -1;
            num_divisor *= -1;
        }
        else if (num_divisor < 0){
            num_divisor *= -1;
            verificaNeg = true;
        }
            

        for(; num_dividendo > num_calculo && (num_calculo + num_divisor <= num_dividendo); quociente++) num_calculo += num_divisor;
        
        if(num_dividendo == num_calculo)
            resto = 0;
        else
            resto = num_dividendo - num_calculo; 

        if(verificaNeg)
            quociente *= -1;

        //mostrando resultados
        printf("Valor quociente: %d\nValor do resto: %d\n", quociente, resto);
        printf("Digite 0 caso queira finalizar ou digite qualquer outro número caso queira fazer outra operação.\n");
        scanf("%d", &verifica);

    }while(verifica != 0);
    return 0;
}