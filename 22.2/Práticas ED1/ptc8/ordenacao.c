#include "ordenacao.h"
#include <stdlib.h>

// Manter como especificado
Time *alocaVetor(int n) {
 Time * times = (Time*) malloc(n * sizeof(Time));
    for(int i = 0; i < n; i++){
        times[i].identifier = i+1;
        times[i].basket = 0;
        times[i].basket2 = 0;
        times[i].balance = 0;
        times[i].vict = 0;
        times[i].def = 0;
        times[i].points = 0;
    }
    return times;
}

// Manter como especificado
void desalocaVetor(Time **vetor) {
    free(*vetor);
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(Time *v, int n) {
   build_heap(v, n);
    while(n>1){
        Time aux = v[n-1];
        v[n-1] = v[0];
        v[0] = aux;
        n--;
        
        heap(v, 0, n-1);
    } 
}

// compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const Time t1, const Time t2) {
    //points
    if(t1.points < t2.points)
        return 1;
    else if(t1.points > t2.points)
        return 0;
    
    //cestas
    else if(t1.balance < t2.balance)
        return 1;
    else if(t1.balance > t2.balance)
        return 0;

    //cesta
    else if(t1.basket < t2.basket)
        return 1;
    else if(t1.basket > t2.basket)
        return 0;

    //inscricao
    else if(t1.identifier > t2.identifier)
        return 1;
    else 
        return 0;
}

void heap(Time * times, int left, int right){
    int i = left;
    int j = i*2 + 1;
    Time aux = times[i];
    while(j <= right){
        
        if(j < right && !compare(times[j], times[j+1]))
            j++;
        if(compare(aux, times[j]))
            break;
        times[i] = times[j];
        i = j;
        j = i*2 +1;
    }
    times[i] = aux;
}

void build_heap(Time * v, int n){
    int left = (n/2)-1;
    while(left >= 0 ){
        heap(v, left, n-1);
        left--;
    }
}

void Dados(int time1, int points1, int time2, int points2, Time * times){  
    int posTime1 = time1-1;
    int posTime2 = time2-1;
    
    if(points1 > points2){
        times[posTime1].points += 2;
        times[posTime1].vict ++;
        times[posTime2].points +=1;
        times[posTime2].def++;
    }
    else{
        times[posTime2].points +=2;
        times[posTime2].vict ++;
        times[posTime1].points +=1;
        times[posTime1].def ++;
    }
    times[posTime1].basket += points1;
    times[posTime1].basket2 += points2;
    times[posTime2].basket += points2;
    times[posTime2].basket2 += points1;
}

void calcbalance(Time * vetor, int n){
    int Basket1;
    int Basket2;
    float Balance1; 

    for(int i = 0; i< n; i++){
        Basket1 = vetor[i].basket;
        Basket2 = vetor[i].basket2;
        if(Basket2 == 0)
            Balance1 = vetor[i].basket;   
        else
            Balance1 = ((float)Basket1)/Basket2;
        vetor[i].balance = Balance1;
    }
}