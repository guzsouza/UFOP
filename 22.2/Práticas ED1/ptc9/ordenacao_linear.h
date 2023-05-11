# ifndef ordena_linear_h
# define ordena_linear_h

#define MAX_M 7
#define MAX_N 10000

typedef struct {
    int senha[MAX_M + 1];
    char nome[21];
} Paciente;

// Manter como especificado
void le(Paciente*, int, int);

// Manter como especificado
void imprime(Paciente*, int, int);

// Manter como especificado
void coutingSort(Paciente*, Paciente*, int, int , int);

// Manter como especificado
void radixSort(Paciente*, int, int);

//copia os dados de um vetor para o outro
void copiaDados(Paciente*, Paciente*, int , int);

# endif // ordena_linear_h
