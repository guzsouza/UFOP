#ifndef ordenacao_h
#define ordenacao_h

typedef struct
{
    char nome[65];
    char cor[10];
    char tam;
} Aluno;

void rebuildHeap(Aluno *alunos, int esq, int dir);
void buildHeap(Aluno *alunos, int n);
int compare(Aluno p1, Aluno p2);
void heapSort(Aluno *alunos, int n);


#endif