#include <stdio.h>


int main() {

    int c, n, i, j, sum, count;
    float avg, above_avg_percent;

    scanf("%d", &c);

    for (i = 0; i < c; i++) {

        scanf("%d", &n);
        sum = 0;
        count = 0;
        int grades[n];

        for (j = 0; j < n; j++) {
            scanf("%d", &grades[j]);
            sum += grades[j];
        }

        avg = (float) sum / n;
        for (j = 0; j < n; j++) {
            if (grades[j] > avg) {
                count++;
            }
        }

        above_avg_percent = (float) count / n * 100;

        printf("%.3f%%\n", above_avg_percent);
    }
    return 0;
}