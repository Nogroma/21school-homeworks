#include "../data_libs/data_io.h"
#include "decision.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
    double *data;
    int n;
    printf("Введите количество ячеек массива:\n");
    scanf("%d", &n);
    data = (double *)malloc(n * sizeof(int));
    input(data, n);

    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
