#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int input(int *a, int *n) {
    printf("Введите количество ячеек массива\n");

    if (scanf("%d", n) != 1 || *n > NMAX || *n <= 0) {
        return 1;
    };

    for (int *p = a; p - a < *n; p++) {
        printf("Введите элемент массива: ");
        scanf("%d", p);
    }

    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("> %d\n", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}

int main() {
    int n, data[NMAX];

    int input_code = input(data, &n);
    if (input_code != 0) {
        printf("n/a");

        return 1;
    }

    squaring(data, n);
    output(data, n);

    return 0;
}
