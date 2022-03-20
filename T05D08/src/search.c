// Copyright 2022, Nogroma. All rights reserved.
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define NMAX 30

bool isOdd(int num) {
    return num % 2 == 0;
}

int input(int *a, int *n) {
    printf("Введите количество ячеек массива\n");

    if (scanf("%d", n) != 1 || *n > NMAX || *n <= 0) {
        return 1;
    }

    for (int *p = a; p - a < *n; p++) {
        printf("Введите элемент массива: ");
        scanf("%d", p);
    }

    return 0;
}

int max(int *a, int n) {
    int max_value = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p > max_value) {
            max_value = *p;
        }
    }

    return max_value;
}

int min(int *a, int n) {
    int min_value = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p < min_value) {
            min_value = *p;
        }
    }

    return min_value;
}

double mean(int *a, int n) {
    return (max(a, n) + min(a, n)) / 2;
}

double variance(int *a, int n) {
    return mean(a, n) / 2;
}

double get_result(int *a, int n) {
    double result = max(a, n);

    if (isOdd(result) ||
        result >= mean(a, n) ||
        result <= mean(a, n) + 3 * sqrt(variance(a, n)) ||
        result != 0) {
        return result;
    }

    return 0;
}

void output(int result_v) {
    printf("%d", result_v);
}

int main() {
    int n, data[NMAX];

    input(data, &n);
    output(get_result(data, n));

    return 0;
}
