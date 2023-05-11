#include <stdio.h>
#include <string.h>
#include <time.h>

#include "indiceInvertido.h"

int main() {
    double tempo_gasto = 0.0;
    clock_t inicio = clock();

    int quantDocs;
    char nomeDoc[D], comando;
    Chave chaves[NN], listaPesquisa[NN];
    NomeDocumento resultadoPesquisa[ND];
    

    IndiceInvertido tabelaHash;
    inicia(tabelaHash);

    scanf("%d", &quantDocs);
    
    for(int i = 0; i < quantDocs; i++) {
        scanf("%s", nomeDoc);

        int quantChaves = pegarChaves(chaves);

        
        for(int j = 0; j < quantChaves; j++)
            if(!insereDocumento(tabelaHash, chaves[j], nomeDoc)) printf("ERROR: Problema pra adicionar chave\n");
        
    }
    
    scanf("%c", &comando);

    //buscar
    if(comando == 'B') {
        int quantPesquisa = pegarChaves(listaPesquisa);
        int tamPesquisa = consulta(tabelaHash, listaPesquisa, quantPesquisa, resultadoPesquisa);
        if(tamPesquisa == 0)
            printf("none\n");
        else 
            for(int i = 0; i < tamPesquisa; i++)
                printf("%s\n", resultadoPesquisa[i]);
    } 
    
    //imprimir
    else if (comando == 'I') imprime(tabelaHash);
    
    clock_t fim = clock();
    tempo_gasto += (double) (fim - inicio) / CLOCKS_PER_SEC;


    //printf("contador: %d\n", contador(tabelaHash));
    //printf("Tempo de execucao: %f segundos\n", tempo_gasto);
    return 0;
}
