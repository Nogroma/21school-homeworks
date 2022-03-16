// // Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>
#include <math.h>

double calc_agnesi(double x) {
    return 1 / (1 + x * x);
}

double calc_lemnis_bern(double x) {
    return sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
}

double calc_hyperbola(double x) {
    return 1 / (x * x);
}

void print_row(double x, double agnesi, double lemnis_bern, double quad_hyperbola) {
    printf("%.7lf | ", x);

    if (agnesi != agnesi || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        printf("- | ");
    } else {
        printf("%.7lf | ", agnesi);
    }

    if (lemnis_bern != lemnis_bern) {
        printf("- | ");
    } else {
        printf("%.7lf | ", lemnis_bern);
    }

    if (quad_hyperbola != quad_hyperbola || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        printf("-");
    } else {
        printf("%.7lf", quad_hyperbola);
    }
}

int main() {
    double pi = 3.141592653589793238462;

    for (double x = -pi; x <= pi; x += 2 * pi / 41) {
        double agnesi = calc_agnesi(x);
        double lemnis_bern = calc_lemnis_bern(x);
        double quad_hyperbola = calc_hyperbola(x);

        print_row(x, agnesi, lemnis_bern, quad_hyperbola);

        if (x + 2 * pi / 41 <= pi) {
            printf("\n");
        }
    }

    return 0;
}