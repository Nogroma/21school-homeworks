// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>
#include <math.h>

int main() {
    double x, y;

    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("n/a");
        return 1;
    }

    if ((x * x + y * y) <= 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }

    return 0;
}
