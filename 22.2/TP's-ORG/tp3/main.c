#include "cpu.h"
#include "generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char**argv) {

    srand(1507);   // Inicializacao da semente para os numeros aleatorios.

    if (argc != 7) {
        printf("Numero de argumentos invalidos! Sao 7.\n");
        // printf("Linha de execucao: ./exe TIPO_INSTRUCAO [TAMANHO_RAM|ARQUIVO_DE_INSTRUCOES] TAMANHO_L1 TAMANHO_L2 TIPO_DE_MAPEAMENTO\n"); // TIPO_DE_MAPEAMENTO: 0 = Random; 1 = FIFO; 2 = LFU; 3 = LRU; 4 = Direto;
        printf("Linha de execucao: ./exe TIPO_INSTRUCAO TAMANHO_M_EXTERNA [TAMANHO_RAM|ARQUIVO_DE_INSTRUCOES] TAMANHO_L1 TAMANHO_L2\n");
        printf("\tExemplo 1 de execucao: ./exe random 100 10 2 4 8\n");
        printf("\tExemplo 2 de execucao: ./exe file 100 arquivo_de_instrucoes.txt\n");
        return 0;
    }

    int memoriesSize[5];
    Machine machine;
    Instruction *instructions;

    memoriesSize[2] = atoi(argv[4]); //l1 
    memoriesSize[3] = atoi(argv[5]); //l2
    memoriesSize[4] = atoi(argv[6]); //l3
    // int Map_Type = atoi(argv[6]);

    /*
    if(Map_Type < 0 || Map_Type > 4){
        printf("Invalid option.\n");
        return 0;
    }
    */

    if (strcmp(argv[1], "random") == 0) {
        memoriesSize[0] = atoi(argv[2]);
        memoriesSize[1] = atoi(argv[3]);
        instructions = generateRandomInstructions(memoriesSize[0]);
    } else if (strcmp(argv[1], "file") == 0) {
        instructions = readInstructions(argv[2], memoriesSize);
    } 
    else {
        printf("Invalid option.\n");
        return 0;
    }
    
    printf("Starting machine...\n");
    start(&machine, instructions, memoriesSize); //inicia a máquina com os valores que o usuário entrou.
    if (memoriesSize[0] < 10)
        printMemories(&machine);
    
    run(&machine);
    if (memoriesSize[0] < 10)
        printMemories(&machine);
    stop(&machine);
    printf("Stopping machine...\n");
    
    return 0;
}