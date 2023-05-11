#ifndef ponto_h
#define ponto_h

typedef struct {
    int x;
    int y;
} Coordenada;

typedef struct {
    char nome[20];
    Coordenada *coordenadas;
    float distancia;
    float deslocamento;
} Ponto;

void lerQuantidade(int*, int*);

Ponto* alocaPontos(int, int);

void desalocaPontos(Ponto*, int);

void lerPontos(Ponto*, int, int);

void calcularDistancia(Ponto*, int, int);

void calcularDeslocamento(Ponto*, int, int);

void mergeSort(Ponto *pontos, int l, int r, int qntPontos);

void merge(Ponto *pontos, int l, int m, int r, int qntPontos);

void imprime(Ponto*, int);


// */
/*
ordena
imprime
*/

#endif