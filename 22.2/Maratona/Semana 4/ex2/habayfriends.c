#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100

typedef struct {
    char NAME[MAX_NAME];
    int sizeNAME;
}Amigo;

typedef struct {
    char NAME[MAX_NAME];
}NOTAmigo;

void notFriend(NOTAmigo * NOTfriends, int start, int end);
void friend(Amigo * friends, int start, int end);


int main(){

    char NAME[MAX_NAME];
    char amigo[5];

    int sizeAmigo = 0;
    int sizeNOTAmigo = 0;
    
    Amigo * friends = malloc(sizeof(Amigo) * 0);
    NOTAmigo * NOTfriends = malloc(sizeof(NOTfriends) * 0);

    Amigo amigoEscolhido;
    amigoEscolhido.sizeNAME = -1;

    scanf("%s", NAME);
    
    int index;

    while (strcmp(NAME, "FIM") != 0){
        scanf("%s", amigo);

        if(strcmp(amigo, "YES") == 0){
            sizeAmigo++;
            friends = realloc(friends, sizeAmigo * sizeof(Amigo));

            index = sizeAmigo-1;

            friends[index].sizeNAME = strlen(NAME);
            strcpy(friends[index].NAME, NAME);

            if(friends[index].sizeNAME > amigoEscolhido.sizeNAME){
                amigoEscolhido.sizeNAME = friends[index].sizeNAME;
                strcpy(amigoEscolhido.NAME, NAME);
            }
            
        }
        else{
            sizeNOTAmigo++;
            NOTfriends = realloc(NOTfriends, sizeNOTAmigo * sizeof(NOTAmigo));

            strcpy(NOTfriends[sizeNOTAmigo-1].NAME, NAME);
        }

        scanf("%s", NAME);
    }
    
    friend(friends, 0, sizeAmigo-1);
    notFriend(NOTfriends, 0, sizeNOTAmigo-1);
    
    for(int i = 1; i < sizeAmigo; i++){
        if(strcmp(friends[i].NAME, friends[i-1].NAME) != 0)
            printf("%s\n", friends[i-1].NAME);
    }
    printf("%s\n", friends[sizeAmigo-1].NAME);


    for(int i = 1; i < sizeNOTAmigo; i++){
        if(strcmp(NOTfriends[i].NAME, NOTfriends[i-1].NAME) != 0)
            printf("%s\n", NOTfriends[i-1].NAME);
    }
    printf("%s\n", NOTfriends[sizeNOTAmigo-1].NAME);


    printf("\nAmigo do Habay:\n%s\n", amigoEscolhido.NAME);

    free(friends);
    free(NOTfriends);

    return 0;
}

void notFriend(NOTAmigo * NOTfriends, int start, int end){
    int i, j;
    NOTAmigo pivo; 

    i = start;
    j = end;
    pivo = NOTfriends[(start + end) / 2];

    while (i <= j){
        while (strcmp(NOTfriends[i].NAME, pivo.NAME) < 0 && i < end)
            i++;
        
        while (strcmp(NOTfriends[j].NAME, pivo.NAME) > 0 && j > start)
            j--;

        if (i <= j){
            NOTAmigo aux = NOTfriends[i];
            NOTfriends[i] = NOTfriends[j];
            NOTfriends[j] = aux;
            i++;
            j--;
        }
    }

    if (j > start)
        notFriend(NOTfriends, start, j);

    if (i < end)
        notFriend(NOTfriends, i, end);
}

void friend(Amigo * friends, int start, int end){
    int i, j;
    Amigo pivo; 

    i = start;
    j = end;
    pivo = friends[(start + end) / 2];

    while (i <= j){
        while (strcmp(friends[i].NAME, pivo.NAME) < 0 && i < end)
            i++;
        
        while (strcmp(friends[j].NAME, pivo.NAME) > 0 && j > start)
            j--;

        if (i <= j){
            Amigo aux = friends[i];
            friends[i] = friends[j];
            friends[j] = aux;
            i++;
            j--;
        }
    }

    if (j > start)
        friend(friends, start, j);
    if (i < end)
        friend(friends, i, end);
}