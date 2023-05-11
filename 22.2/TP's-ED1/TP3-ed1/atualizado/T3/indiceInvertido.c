#include <stdio.h>
#include <string.h>

#include "indiceInvertido.h"


void inicia(IndiceInvertido tabelaHash) {
    for(int i = 0; i < M; i++) {
        tabelaHash[i].n = 0;
        tabelaHash[i].sofreuColisao = false;
        strcpy(tabelaHash[i].chave, VAZIO);

        for(int j = 0; j < ND; j++) 
            strcpy(tabelaHash[i].documentos[j], VAZIO);
    }
}

bool insereDocumento(IndiceInvertido tabelaHash, Chave chave, NomeDocumento documento) {
    int posicao = busca(tabelaHash, chave);
    
    if(posicao == -1) {
        posicao = h(chave, M);
        int j = 0;
        
        //se a nova posição ja está ocupada
        while(strcmp(tabelaHash[(posicao + j) % M].chave, VAZIO) != 32 && j < M)
            j++;
        
        strcpy(tabelaHash[(posicao + j) % M].chave, chave);
        strcpy(tabelaHash[(posicao + j) % M].documentos[tabelaHash[posicao].n], documento);
        tabelaHash[(posicao + j) % M].n++;
        
        
        if(j > 0) 
            //true para colisão
            tabelaHash[(posicao + j) % M].sofreuColisao = true;
        

        return 1;
    } else if(posicao >= 0 && posicao < M){

        strcpy(tabelaHash[posicao].documentos[tabelaHash[posicao].n], documento);
        tabelaHash[posicao].n++;

        return 1;
    }

    return 0;
}

int busca(IndiceInvertido tabelaHash, Chave chave) {
    //retorna posição da chave ou -1 caso ela não exista na tabela
    int j = 0;
    int ini = h(chave, M);

    while(strcmp(tabelaHash[(ini + j) % M].chave, VAZIO) != 0 &&
          strcmp(tabelaHash[(ini + j) % M].chave, chave) != 0 &&
          j < M) {
            j++;
    }
    
    if(strcmp(tabelaHash[(ini + j) % M].chave, chave) == 0){
        return (ini + j) % M;
    }
    
    return -1;
}

void sort(NomeDocumento* arr, int n) {
    int gap, i, j;
    NomeDocumento temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i-gap; j >= 0 && strcmp(arr[j], arr[j+gap]) > 0; j -= gap) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+gap]);
                strcpy(arr[j+gap], temp);
            }
        }
    }
}

int consulta(IndiceInvertido tabelaHash, Chave* listaPesquisa, int quantPesquisa, NomeDocumento* resultadoPesquisa) {
    if (busca(tabelaHash, listaPesquisa[0]) == -1) return 0;
    
    Item tabela1 = tabelaHash[busca(tabelaHash, listaPesquisa[0])];
    NomeDocumento aux[ND];

    for(int i = 1; i < quantPesquisa; i++) {
        int cont = 0;
        int resultadoBusca = busca(tabelaHash, listaPesquisa[i]);
        
        if(resultadoBusca == -1) return 0;
        
        Item tabela2 = tabelaHash[resultadoBusca];

        for(int j = 0; j < tabela1.n; j++)
            for(int k = 0; k < tabela2.n; k++)
                if(strcmp(tabela1.documentos[j], tabela2.documentos[k]) == 0) {
                    //se os nomes forem iguais, contador de iguais++, copia no vetor auxiliar
                    strcpy(aux[cont], tabela1.documentos[j]);
                    cont++;
                }
        
        for (int x = 0; x < cont; x++)
            strcpy(tabela1.documentos[x], aux[x]);

        tabela1.n = cont;
    }

    for (int x = 0; x < tabela1.n; x++)
        //passa pro vetor resultadoPesquisa os nomes dos documentos em comum
        strcpy(resultadoPesquisa[x], tabela1.documentos[x]);

    sort(resultadoPesquisa, tabela1.n);

    return tabela1.n;
}


void imprime(IndiceInvertido tabela){

    int contador = 0;
    
    for(int i=0; i<M; i++){
       
        if (strcmp(tabela[i].chave, VAZIO) != 32 ){

            if (tabela[i].sofreuColisao == true)
                contador++;

            printf("%s - ", tabela[i].chave);
        
            for(int j=0; j<tabela[i].n; j++){
                printf("%s ", tabela[i].documentos[j]);
            }
            
            printf("\n");
        }
    }
    
}

int contador(IndiceInvertido tabela){
   //contador de colisões 
    int contador = 0;

    for (int index = 0; index < M; index++){
        if (strcmp(tabela[index].chave, VAZIO) != 32)
            if (tabela[index].sofreuColisao == true)
                contador++;
    }

    return contador;
}