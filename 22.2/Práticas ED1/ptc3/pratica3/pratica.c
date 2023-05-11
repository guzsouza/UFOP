#include <stdio.h>
#include "duende.h"
#include "dtime.h"

//A função proximo mais velho tem complexidade O(n), pois a função passa por todos os elementos do vetor, fazendo comparações entre eles.

//Na função escalar times, a complexidade é de (n/3)*3, ou seja, n. Detalhando melhor, vão ser rodados 3 "for" dos times, eles vão rodar 3 vezes. n=número de duendes.


int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 3;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes);
    printTimes(times, qtdTimes);
    desalocaDuendes(&duendes);
    desalocaTimes(&times, qtdTimes);

    return 0; //nao remova
}
