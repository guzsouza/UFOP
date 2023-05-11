#include <stdio.h>
#include <string.h>

#define MAX 65

typedef struct Camiseta {
    char nome[MAX];
    char cor[MAX];
    char tamanho;
} Camiseta;

int compara_cores(Camiseta *a, Camiseta *b) {
    Camiseta *p1 = (Camiseta *) a;
    Camiseta *p2 = (Camiseta *) b;

    return strcmp(p1->cor, p2->cor);
}

int compara_tamanhos(Camiseta *a, Camiseta *b) {
    Camiseta *p1 = (Camiseta *) a;
    Camiseta *p2 = (Camiseta *) b;

    if (p1->tamanho == p2->tamanho) {
        return 0;
    } else if (p1->tamanho == 'G') {
        return -1;
    } else if (p1->tamanho == 'M' && p2->tamanho == 'G') {
        return 1;
    } else {
        return -1;
    }
}

int compara_nomes(Camiseta *a, Camiseta *b) {
    Camiseta *p1 = (Camiseta *) a;
    Camiseta *p2 = (Camiseta *) b;

    return strcmp(p1->nome, p2->nome);
}

int main() {
    int n, i;
    Camiseta camisetas[MAX * MAX];

    while (scanf("%d", &n) && n != 0) {
        for (i = 0; i < n; i++) {
            scanf("%s", camisetas[i].nome);
            scanf("%s", camisetas[i].cor);
            getchar();
            camisetas[i].tamanho = getchar();
        }

        qsort(camisetas, n, sizeof(Camiseta), compara_cores);
        qsort(camisetas, n, sizeof(Camiseta), compara_tamanhos);
        qsort(camisetas, n, sizeof(Camiseta), compara_nomes);

        for (i = 0; i < n; i++) {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }

        printf("\n");
    }

    return 0;
}