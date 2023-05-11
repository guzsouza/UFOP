#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[25];
    char region;
    int distance;
} PersonInfo;

int person_compare(PersonInfo , PersonInfo );
void swap(PersonInfo *, int *, int *);
void quicksort(PersonInfo *, int , int );

int main() {
    PersonInfo *people;
    int num_cases;

    while (scanf("%d", &num_cases) != EOF) {
        people = (PersonInfo*) malloc(num_cases * sizeof(PersonInfo));

        for (int i = 0; i < num_cases; i++) {
            scanf("%s", people[i].name);
            getchar();
            scanf("%c", &people[i].region);
            getchar();
            scanf("%d", &people[i].distance);
            getchar();
        }

        quicksort(people, 0, num_cases - 1);

        for (int j = 0; j < num_cases; j++) {
            printf("%s\n", people[j].name);
        }

        free(people);
    }

    return 0;
}

int person_compare(PersonInfo person1, PersonInfo person2) {
    if (person1.distance < person2.distance) {
        return 1;
    } else if (person1.distance > person2.distance) {
        return 2;
    } else {
        if (person1.region < person2.region) {
            return 1;
        } else if (person1.region > person2.region) {
            return 2;
        } else {
            if (strcmp(person1.name, person2.name) < 0) {
                return 1;
            } else if (strcmp(person1.name, person2.name) > 0) {
                return 2;
            }
        }
    }

    return 0;
}

void swap(PersonInfo *vetor, int *i, int *j) {
    PersonInfo temp;

    temp = vetor[*i];
    vetor[*i] = vetor[*j];
    vetor[*j] = temp;
    *i += 1;
    *j -= 1;
}

void quicksort(PersonInfo *vetor, int begin, int end) {
    int i, j;
    PersonInfo pivot;

    i = begin;
    j = end;
    pivot = vetor[(begin + end) / 2];

    while (i <= j) {
        while (person_compare(vetor[i], pivot) == 1 && i < end) {
            i++;
        }
        while (person_compare(vetor[j], pivot) == 2 && j > begin) {
            j--;
        }
        if (i <= j) {
            swap(vetor, &i, &j);
        }
    }

    if (j > begin) {
        quicksort(vetor, begin, j);
    }

    if (i < end) {
        quicksort(vetor, i, end);
    }
}