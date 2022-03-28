#include "../data_libs/data_io.h"
#include "data_process.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
    double *data;
    int n;

    printf("Введите количество ячеек массива:\n");
    scanf("%d", &n);
    data = (double *)malloc(n * sizeof(int));
    // Don`t forget to allocate memory !
    printf("Заполните массив:\n");
    input(data, n);

    if (normalization(data, n)) {
        output(data, n);
    } else {
        printf("ERROR");
    }

    free(data);
    return 0;
}
