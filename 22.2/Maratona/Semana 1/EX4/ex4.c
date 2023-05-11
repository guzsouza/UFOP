#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura de uma lista, ou melhor, de uma pilha.
typedef struct{
    int Funny;
} Titem;

typedef struct Cel{
    struct Cel *Prox_Cel, *Back_Cel;
    Titem Item_Cel;
} Tcel;

typedef struct{
    Tcel *T_Head, *T_Last;
} Tlist;

void Tlista_Inicia(Tlist *plist);
int Verify_Null_List(Tlist *plist);
void Include_List(Tlist *plist, int Funny_Escale, Tlist *Pilha);
void POP_Last(Tlist *plist);
void Esvazia_Lista(Tlist *plist);
int ListaInsereInicio(Lista* pLista, Item item);


int main(void){
    int Num_Op;
    int Funny_Escale;
    char Str_Op[5];
    scanf("%d", &Num_Op);
    Tlist *List = (Tlist*) malloc(sizeof(Tlist));
    TList Pilha;

    Tlista_Inicia(List);
    Tlista_Inicia(&Pilha);

    for(int i=0; i != Num_Op; i++){
        printf("\nnofor\n");

        for(int index=0; index<4; index++){
            scanf(" %c", &Str_Op[index]);
            if (Str_Op[index] =='\n')
                break;
            if (Str_Op[index] =='\r')
                break;
            if(index>1 && Str_Op[1]=='I')
                break;
            if(index>1&& Str_Op[1]=='O')
                break;
        }        

        if(Str_Op[1]=='U'){
            scanf("%d", &Funny_Escale);
            Include_List(List, Funny_Escale, &Pilha);
        }
        else if(Str_Op[1]=='I'){
            if (Verify_Null_List(List))
                printf("EMPTY\n");
            else
                printf("%d\n", List->T_Head->Prox_Cel->Item_Cel.Funny);
        }
        else if(Str_Op[1]=='O'){
            printf("\nif do pop\n");
            if (Verify_Null_List(List))
                printf("EMPTY\n");
            else {
                printf("\npopando\n");
                POP_Last(List);
            }
        }
    }
    Esvazia_Lista(List);
}

void Tlista_Inicia(Tlist *plist){
    plist->T_Head =  (Tcel*) malloc (sizeof(Tcel));
    plist->T_Last =  (Tcel*) malloc (sizeof(Tcel));
    plist->T_Last->Prox_Cel = NULL;
    plist->T_Last->Back_Cel = plist->T_Head;
    plist->T_Head->Prox_Cel = plist->T_Last;
    plist->T_Head->Back_Cel = NULL;
}

int Verify_Null_List(Tlist *plist){

    if (plist==NULL)
        return 1;
    if (plist->T_Head->Prox_Cel == plist->T_Last)
        return 1;
    else return 0;
}

void Include_List(Tlist *plist, int Funny_Escale, Tlist *Pilha){
    //alocação de uma nova célula
    Tcel *Novo = (Tcel*) malloc (sizeof(Tcel));
    if(Novo==NULL)
        return;

    if (Verify_Null_List(plist)){
        
        printf("\nentrou no if de lista vazia\n");
        plist->T_Last->Back_Cel = Novo;
        plist->T_Head->Prox_Cel = Novo;
        Novo->Prox_Cel = plist->T_Last;
        Novo->Back_Cel = plist->T_Head;
        Novo->Item_Cel.Funny = Funny_Escale;
        ListaInsereInicio(Pilha);
        printf("\nsaiu do if lista vazia\n");
        return;
    }
    
    if (Funny_Escale < plist->T_Head->Prox_Cel->Item_Cel.Funny){
        
        printf("\nentrou no if de menor da lista\n");
        Novo->Prox_Cel = plist->T_Head->Prox_Cel;
        plist->T_Head->Prox_Cel = Novo;
        Novo->Prox_Cel->Back_Cel=Novo;
        Novo->Back_Cel=plist->T_Head;
        Novo->Item_Cel.Funny=Funny_Escale;
        Tcel *Cel_Atual = plist->; ///aqui

        while(Cel_Atual != NULL){
            if(Cel_Atual->Prox_Cel == NULL){
                Cel_Atual->Prox_Cel = Novo;
                Cel_Atual->Prox_Cel->Back_Cel = Cel_Atual;
                Cel_Atual->Prox_Cel->Prox_Cel = NULL;
            }
            Cel_Atual= Cel_Atual->Prox_Cel;
        }
        return;
    }

    Tcel *Celula_Atual = plist->T_Last->Back_Cel;
    while(Celula_Atual->Back_Cel != NULL){
        printf("\nentrou no while include\n");
        
        if(Funny_Escale > Celula_Atual->Item_Cel.Funny){
            
            printf("\nentrou no if do while include\n");
            Celula_Atual->Prox_Cel->Back_Cel=Novo;
            Novo->Prox_Cel=Celula_Atual->Prox_Cel;
            Celula_Atual->Prox_Cel=Novo;
            Novo->Back_Cel = Celula_Atual;
            Novo->Item_Cel.Funny=Funny_Escale;
            

            Tcel *Cel_Atual = plist->;  ///aqui

            while(Cel_Atual != NULL){
                if(Cel_Atual->Prox_Cel == NULL){
                    Cel_Atual->Prox_Cel = Novo;
                    Cel_Atual->Prox_Cel->Back_Cel = Cel_Atual;
                    Cel_Atual->Prox_Cel->Prox_Cel = NULL;
                }
                Cel_Atual= Cel_Atual->Prox_Cel;
            }
            return;
        }
        Celula_Atual = Celula_Atual->Back_Cel;
    }
}

void POP_Last(Tlist *plist){

    printf("\nchegou no pop\n");
    
    if(Verify_Null_List(plist))
        return;
    
    Tcel *Cel_Atual = plist->;  ///aqui

    while(Cel_Atual != NULL){
        printf("\nwhile do pop, termo %d\n", Cel_Atual->Item_Cel.Funny);
        if(Cel_Atual->Prox_Cel->Prox_Cel == NULL){
            printf("\nif do pop, termo %d\n", Cel_Atual->Item_Cel.Funny);
            free(Cel_Atual);
            break;
        }
        Cel_Atual=Cel_Atual->Prox_Cel;
    }
    printf("\nretirou\n");
}

void Esvazia_Lista(Tlist *plist){

    if(Verify_Null_List(plist)){
        free(plist->T_Head);
        free(plist->T_Last);
        free(plist);
        return;
    }

    Tcel* Future_Cel = plist->T_Head->Prox_Cel;
    Tcel* Aux = Future_Cel;

    while(Future_Cel != NULL){ 
        Aux= Future_Cel->Prox_Cel;
        free(Future_Cel);
        Future_Cel=Aux;  
    }

    free(plist->T_Head);
    free(plist);

}

int ListaInsereInicio(Lista* pLista, Item item) {
    
    Celula* Novo = ( Celula*) malloc (sizeof( Celula));  //alocação de uma nova célula da lista.
    
    if(Novo == NULL)  //verificação se a alocação foi bem sucedida.
        return 0;


    if (ListaEhVazia(pLista)){  //caso a lista for vazia, a última célula da lista também vai ser a primeira.
        Novo->prox= NULL;
        pLista->ultimo = Novo;
        pLista->cabeca->prox = Novo;
        Novo->item = item;
    } 
    else{
        Novo->prox = pLista->cabeca->prox;
        pLista->cabeca->prox = Novo;
        Novo->item = item;
    }
    return 1;
}