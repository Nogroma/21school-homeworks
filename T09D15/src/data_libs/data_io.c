#include "data_io.h"
#include "stdio.h"


void input(double *data, int n) {
    printf("Заполните массив:");
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            printf("n/a");
        }
    }
}

void output(double *data, int n) {
    printf("Полученный массив: \n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", data[i]);
    }
}
