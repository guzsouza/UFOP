#include <stdio.h>
#include "duende.h"

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    //Na função escalar times, a complexidade é de (n/4)*4, ou seja, n. Detalhando melhor, vão ser rodados 4 "for" dos times, eles vão rodar n vezes. n=número de duendes.

    //a complexidade é ótima (n-1).

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 4;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes);
    printTimes(times, qtdTimes);
    desalocaDuendes(&duendes);
    desalocaTimes(&times);

    return 0; //nao remova
}
