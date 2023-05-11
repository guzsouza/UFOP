#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "indiceInvertido.h"


bool inicia(IndiceInvertido tabelaHash) {

    for(int i = 0; i < M; i++) {

        tabelaHash[i].cabeca = (Celula*) malloc(sizeof(Celula));

        if (tabelaHash[i].cabeca == NULL)
            return false;

        tabelaHash[i].ultimo = tabelaHash[i].cabeca;
        tabelaHash[i].cabeca->prox = NULL;
        tabelaHash[i].aponta = false;
    }
    return true;
}

bool insereDocumento(IndiceInvertido tabelaHash, Chave chave, NomeDocumento documento) {

    Coordenada pos;
    int posicao = busca(tabelaHash, chave, &pos);

    if (posicao == -2)
        return false;
    
    //caso aconteça o -1, é possível que a tabela da posição está vazia, mas também é possível que não, somente não contém a chave;
    if(posicao == -1 || posicao == -3) {
        int posicao1 = h(chave, M);

        Celula* Novo = (Celula*) malloc (sizeof(Celula));  //alocação de uma nova célula da lista.
    
        if(Novo == NULL)  //verificação se a alocação foi bem sucedida.
            return false;

        Novo->prox= NULL;

        if (posicao == -3){  //caso a lista for vazia, a última célula da lista também vai ser a primeira.
            tabelaHash[posicao1].cabeca->prox = Novo;
            tabelaHash[posicao1].ultimo = Novo;
            strcpy(Novo->item.chave, chave);
            strcpy(Novo->item.documentos[0], documento);
            tabelaHash[posicao1].aponta = true;
            Novo->item.n += 1;
        } 
        else{
            tabelaHash[posicao1].ultimo->prox = Novo;
            tabelaHash[posicao1].ultimo = Novo;
            strcpy(Novo->item.chave, chave);
            strcpy(Novo->item.documentos[0], documento);
            Novo->item.n += 1;
        }
        return 1;
    } else if(posicao == 1){

        int NumDocuments = tabelaHash[pos.CasaTabela].cabeca->prox->item.n;

        if (pos.CasaLista == 0){
            strcpy(tabelaHash[pos.CasaTabela].cabeca->prox->item.documentos[NumDocuments], documento);
            tabelaHash[pos.CasaTabela].cabeca->prox->item.n += 1;
            return 1;
        }

        Celula *casaAtual = tabelaHash[pos.CasaTabela].cabeca->prox;

        for (int index = 0; index != pos.CasaLista; index++)
            casaAtual = casaAtual->prox;
        

        strcpy(casaAtual->item.documentos[NumDocuments], documento);

        casaAtual->item.n += 1;
        return 1;
    }

    return 0;
}

int busca(IndiceInvertido tabelaHash, Chave chave, Coordenada *pos) {

    if (tabelaHash == NULL)
        return -2;

    //retorna 1 caso a chave esteja presente e retorna sua coordenada, -1 caso ela não exista na tabela ou -2 caso a tabela esteja nula.
    int j = 0;
    int ini = h(chave, M);

    //caso a posição ideial da tabela esteja vazia, é sinônimo de que a chave não está presente na tabela.
    if (!tabelaHash[ini].aponta)
        return -3;
    

    Celula *casaAtual = tabelaHash[ini].cabeca->prox;
    int index = 0;

    while (casaAtual != NULL){         
        if (strcmp (casaAtual->item.chave, chave) == 0){
            pos->CasaLista = index;
            pos->CasaTabela = ini;
            return 1;
        }
        index++;
        casaAtual = casaAtual->prox;
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
    
    Coordenada position;
    int posicao = busca(tabelaHash, listaPesquisa[0], &position);
    
    if (posicao < 0) 
        return 0;

    Celula *casaAtual = tabelaHash[position.CasaTabela].cabeca->prox;

    for (int index = 0; index != position.CasaLista; index++)
        casaAtual = casaAtual->prox;

    Item tabela1 = casaAtual->item;
    NomeDocumento aux[ND];

    for(int i = 1; i < quantPesquisa; i++) {

        int cont = 0;
        int resultadoBusca = busca(tabelaHash, listaPesquisa[i], &position);
        
        if(resultadoBusca < 0){ 
            casaAtual = NULL;
            free(casaAtual);
            return 0;
        }

        casaAtual = tabelaHash[position.CasaTabela].cabeca->prox;

        for (int index = 0; index != position.CasaLista; index++)
            casaAtual = casaAtual->prox;

        Item tabela2 = casaAtual->item;

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

    casaAtual = NULL;
    free(casaAtual);
    return tabela1.n;
}


void imprime(IndiceInvertido tabela){
    
    Celula *Future_Cel;

    for(int i=0; i<M; i++){
        if (tabela[i].aponta){

            Future_Cel = tabela[i].cabeca->prox;

            while(Future_Cel != NULL){ 
                //print da chave
                printf("%s - ", Future_Cel->item.chave);

                //print dos documentos dentro posição da lista, pertencente a chave.
                for(int j=0; j< Future_Cel->item.n; j++)
                    printf("%s ", Future_Cel->item.documentos[j]);
            
                Future_Cel = Future_Cel->prox;
            }
            printf("\n");
        }
        Future_Cel = NULL;
        free(Future_Cel);
    }
    
}

int contador(IndiceInvertido tabela){
   //contador de colisões 
    int contador = 0;

    for (int index = 0; index < M; index++){
        if (tabela[index].sofreuColisao == true)
            contador++;
    }
    return contador;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista == NULL)
        return true;
    if(pLista->cabeca == pLista->ultimo)
        return true;
    if(pLista->cabeca->prox == NULL)
        return true;
    return false;
}