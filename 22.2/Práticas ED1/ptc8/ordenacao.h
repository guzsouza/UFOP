# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
    int identifier;
    int basket;
    int basket2;
    float balance; 
    int vict;
    int def;
    int points;
} Time;

// Manter como especificado
void ordenacao(Time *vetor, int n);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

void build_heap(Time * , int);

void heap(Time *, int, int);

void Dados(int, int, int, int, Time *);

void calcbalance(Time *, int);

# endif
