#include "ordenacao_linear.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void le(Paciente* pacientes, int n, int m) {
    // PREENCHER AQUI
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */
    char Senha[MAX_M + 1];
    for (int index = 0; index < n; index++){  

        scanf(" %s", Senha);
        scanf(" %s", pacientes[index].nome);

        for (int indexSenha = 0; indexSenha < m; indexSenha++){
            char charsenha = Senha[indexSenha];
            int x = atoi(&charsenha);
            pacientes[index].senha[indexSenha] = x;
        }
    }
        
}

// Manter como especificado
void imprime(Paciente* pacientes, int n, int m){
    // PREENCHER AQUI
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */

    for (int index = 0; index < n; index++){
        for (int indexSenha = 0; indexSenha < m; indexSenha++)
            printf("%d", pacientes[index].senha[indexSenha]);

        printf(" %s\n", pacientes[index].nome);
    }
}

// Manter como especificado
void coutingSort(Paciente* A, Paciente* B, int n, int i, int tamanho_max) {

    // PREENCHER AQUI
    /*
     * A = vetor a ser ordenado
     * B = vetor auxiliar para armazenar o vetor A ordenado
     * n = tamanho do vetor A
     * i = digito a ser usado na ordenacao
     */

    int *vetorAux = (int*) calloc(tamanho_max + 2, sizeof(int));
    int indexB = 0;

    for (int index = 0; index < n; index++){
        int x = A[index].senha[i];
        vetorAux[x] += 1;
    }

    for (int index = 1; index <= tamanho_max; index++)
        vetorAux[index] += vetorAux[index-1];

    for (int index = n - 1; index >= 0; index--){
        int x = A[index].senha[i];
        indexB = vetorAux[x] - 1;
        B[indexB] = A[index];
        vetorAux[A[index].senha[i]] = vetorAux[A[index].senha[i]] - 1;
    }
    free(vetorAux);
}

// Manter como especificado
void radixSort(Paciente* pacientes, int n, int m) {
    // Vetor auxiliar a ser usado no couting sort
    Paciente B[MAX_N];

    copiaDados(pacientes, B, n, m);

    /*
     * pacientes = vetor a ser ordenado
     * n = tamanho do vetor A
     * m = quantidade de digitos
     */

    int maior_valor = 0;
    int indexCasa = m-1;

    //maior valor de cada casa
    for (int indexSenha = 0; indexSenha < m; indexSenha++){
        maior_valor = pacientes[0].senha[indexCasa];

        for (int index = 0; index < n; index++)
            if (maior_valor < pacientes[index].senha[indexCasa])
                maior_valor = pacientes[index].senha[indexCasa]; 

        coutingSort(pacientes, B, n, indexCasa, maior_valor);
        copiaDados(B,pacientes,n,m);

        indexCasa--;
    }   
            
}

void copiaDados(Paciente* A, Paciente* B, int tam, int Senha){
    for (int index = 0; index < tam; index++){
        strcpy(B[index].nome, A[index].nome);
        for (int indexSenha = 0; indexSenha < Senha; indexSenha++)
            B[index].senha[indexSenha] = A[index].senha[indexSenha];
    }
}

