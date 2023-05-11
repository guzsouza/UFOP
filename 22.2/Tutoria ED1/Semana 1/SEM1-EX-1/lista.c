#include "lista.h"

void TLista_Inicia (TLista * pLista ) {
    pLista->TL_Head= (TCelula*) malloc (sizeof(TCelula));
    pLista->TL_Last= pLista->TL_Head;
    pLista->TL_Head->Prox_Cel = NULL;
}

int TLista_EhVazia ( TLista * pLista ) {
    if(pLista == NULL)
        return 1;
    if(pLista->TL_Head->Prox_Cel == NULL)
        return 1;
    return 0;
}

int TLista_Insere_Fim ( TLista * pLista , char x) {

    TCelula* Novo = (TCelula*) malloc (sizeof(TCelula));  //alocação de uma nova célula da lista.
    if(Novo==NULL)  //verificação se a alocação foi bem sucedida.
        return 0;

    Novo->Prox_Cel=NULL;
    Novo->Item_Cel.Letter = x;
    pLista->TL_Last->Prox_Cel=Novo;
    pLista->TL_Last=Novo;
    
    return 1;
}

int TLista_Insere_Inicio ( TLista * pLista , TLista *List2, char x){

    TCelula* Novo = (TCelula*) malloc (sizeof(TCelula));  //alocação de uma nova célula da lista.

    if(Novo==NULL)  //verificação se a alocação foi bem sucedida.
        return 0;

    Novo->Prox_Cel=NULL;

    if (TLista_EhVazia(pLista)){  //caso a lista for vazia, a última célula da lista também vai ser a primeira.
        pLista->TL_Last=Novo;
        pLista->TL_Head->Prox_Cel=Novo;
        Novo->Item_Cel.Letter = x;
    }

    else if (x != '[' && x != ']'){
        TLista_Insere_Fim(List2,x);
    }

    else if (x == '[' && (TLista_EhVazia(List2)))
        return 1;

    else if (x == ']' && (TLista_EhVazia(List2)))
        return 1;

    else if ((x == '[' && (TLista_EhVazia(List2) == 0))){

        TLista_append(List2, pLista);
        TLista_Esvazia_Parcialmente(pLista);
        TCelula* Celula_Atual = List2->TL_Head->Prox_Cel;

        while(Celula_Atual != NULL && Celula_Atual->Item_Cel.Letter != '\r'){
            TLista_Insere_Fim(pLista, Celula_Atual->Item_Cel.Letter);
            Celula_Atual = Celula_Atual->Prox_Cel;
        }

        TLista_Esvazia_Parcialmente(List2);
        TLista_Insere_Fim(List2, x);
    }
    else if ((x == ']' && (TLista_EhVazia(List2) == 0))){

        TLista_append(List2, pLista);
        TLista_Esvazia_Parcialmente(pLista);
        TCelula* Celula_Atual = List2->TL_Head->Prox_Cel;

        while(Celula_Atual != NULL && Celula_Atual->Item_Cel.Letter != '\r'){
            TLista_Insere_Fim(pLista, Celula_Atual->Item_Cel.Letter);
            Celula_Atual = Celula_Atual->Prox_Cel;
        }

        TLista_Esvazia_Parcialmente(List2);
    }
    return 1;
}

void TLista_Esvazia (TLista * pLista){

    TCelula* Future_Cel = pLista->TL_Head->Prox_Cel;
    TCelula* Aux=Future_Cel;

    while(Future_Cel != NULL){ 
        Aux= Future_Cel->Prox_Cel;
        free(Future_Cel);
        Future_Cel=Aux;  
    }

    free(pLista->TL_Head);
    free(pLista);
}

void TLista_Imprime ( TLista * pLista ){
    if(TLista_EhVazia(pLista)) {
        return;
    }
    
    TCelula* Celula_Atual = pLista->TL_Head->Prox_Cel;
    while(Celula_Atual != NULL){ 
        if ((Celula_Atual->Item_Cel.Letter != ']') && (Celula_Atual->Item_Cel.Letter != '['))
            printf("%c", Celula_Atual->Item_Cel.Letter);
        Celula_Atual = Celula_Atual->Prox_Cel;
    }  
}

int Read_Arq(){

    int Home_Verify=0;
    char Total_Text[MAX_TAM + 1];
    int index=0;

    TLista *List = (TLista*) malloc(sizeof(TLista)); //iniciando a Lista, que vai conter as linhas modificadas
    if (List==NULL)
        return 0; 

    TLista *List2 = (TLista*) malloc(sizeof(TLista));
    if (List2==NULL)
        return 0;

    TLista_Inicia(List); //Iniciando a lista
    TLista_Inicia(List2);
    
    int teste = 0;

    while (((Total_Text[index] = getchar()) != EOF) && (index < (MAX_TAM))){ 
        int teste = 0;
        do {
            if(Total_Text[index] == '[' && teste != 0)
                Home_Verify = 1;
            
            else if(Total_Text[index] == ']')
                Home_Verify=0;

            else if((Home_Verify==0) && (Total_Text[index] != '[') && (Total_Text[index] != ']') && (Total_Text[index] != '\r')){
                if (TLista_Insere_Fim(List, Total_Text[index]) == 0)
                    return 0;
                index++;
            }    

            else if((Home_Verify==1) && (Total_Text[index] != '[') && (Total_Text[index] != ']') && (Total_Text[index] != '\r')){
                
                do{ 
                    if (Total_Text[index] !='\r')
                        if (TLista_Insere_Inicio(List, List2, Total_Text[index])==0)
                            return 0;

                    if (Total_Text[index]==']')
                        break;


                }while((Total_Text[index] != '\n') && ((Total_Text[index] = getchar())!= EOF) && (index < (MAX_TAM)) && (Total_Text[index] != '\r'));
                
                Home_Verify=0;
            }

            else index++;

            teste = 1;
        } while (((Total_Text[index] = getchar()) != EOF) && (Total_Text[index] != '\n') && (index < (MAX_TAM-1)));

        TLista_Imprime(List);
        printf("\n");
        TLista_Esvazia_Parcialmente(List);
        TLista_Esvazia_Parcialmente(List2);
    }

    TLista_Esvazia(List2);
    TLista_Esvazia(List);
    return 1;
}

void TLista_Esvazia_Parcialmente(TLista* pLista){

    if(TLista_EhVazia(pLista))
        return;

    TCelula* Future_Cel = pLista->TL_Head->Prox_Cel;
    TCelula* Aux;

    while(Future_Cel != NULL){ 
        Aux= Future_Cel->Prox_Cel;
        free(Future_Cel);
        Future_Cel=Aux;  
    }

    pLista->TL_Last = pLista->TL_Head;
    pLista->TL_Head->Prox_Cel = NULL;
}

//adiciona o conteúdo de uma lista ao final de outra.
void TLista_append(TLista *pLista1, TLista *pLista2){

    if (TLista_EhVazia(pLista2))
        return;

    TCelula* Cel_Atual = pLista2->TL_Head->Prox_Cel;

    while(Cel_Atual != NULL){ 
        TLista_Insere_Fim(pLista1, Cel_Atual->Item_Cel.Letter);
        Cel_Atual = Cel_Atual->Prox_Cel;
    }    
    TLista_Esvazia_Parcialmente(pLista2);
}