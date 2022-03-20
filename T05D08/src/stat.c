#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

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
    return (double)(max(a, n) + min(a, n)) / 2;
}

double variance(int *a, int n) {
    return mean(a, n) / 2;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }

    printf("\n");
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}

int main() {
    int n, data[NMAX];

    input(data, &n);

    output(data, n);

    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}
