// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>
#include <math.h>

float magic_function(float x) {
    return 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2 / x) - 1.01;
}

int main() {
    float x;

    if (scanf("%f", &x) != 1)
    {
        printf("n/a");

        return 1;
    }

    printf("%.1lf", magic_function(x));

    return 0;
}
