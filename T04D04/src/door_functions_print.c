// // // Copyright 2022, Nogroma. All rights reserved.
#include <math.h>
#include <stdio.h>

#define WIDTH 42
#define HEIGH 21
#define LIMIT 2147483647

double calc_agnesi(double x) {
    return 1 / (1 + x * x);
}

double calc_lemnis_bern(double x) {
    return sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
}

double calc_hyperbola(double x) {
    return 1 / (x * x);
}

double calc_agnesi_for_graphic(double x, double limit) {
    double y = calc_agnesi(x);

    if (y != y || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        return limit;
    }

    return y;
}

double calc_lemnis_bern_for_graphic(double x, double limit) {
    double y = calc_lemnis_bern(x);

    if (y != y) {
        return limit;
    }

    return y;
}

double calc_quad_hyperbola_for_graphic(double x, double limit) {
    double y = calc_hyperbola(x);

    if (y != y || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        return limit;
    }

    return y;
}

void graph(double (*func)()) {
    double max = -LIMIT;
    double pi = 3.141592653589793238462;

    double y, x = -pi;

    for (int i = 0; i < WIDTH; i++) {
        y = func(x);
        x += 2 * pi / 41;

        if (y > max && y != LIMIT) {
            max = y;
        }
    }

    for (int i = HEIGH; i > 0; i--) {
        x = -pi;

        for (int j = 0; j < WIDTH; j++) {
            y = func(x);
            x += 2 * pi / 41;

            if (y == LIMIT) {
                printf(" ");
                continue;
            }

            if (y >= max / HEIGH * i && y < max / HEIGH * (i + 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

int main() {
    graph(calc_agnesi_for_graphic);
    printf("------------------------------------------\n");
    graph(calc_lemnis_bern_for_graphic);
    printf("------------------------------------------\n");
    graph(calc_quad_hyperbola_for_graphic);

    return 0;
}
