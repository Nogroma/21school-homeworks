// Copyright 2021, Nogroma. All rights reserved.
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isInteger(double d) {
    return d == (int64_t)d;
}

int division(int a, int b) {
    return a / b;
}

int multiplication(int a, int b) {
    return a * b;
}

int subtraction(int a, int b) {
    return a - b;
}

int sum(int a, int b) {
    return a + b;
}

int main() {
    float first_number_dirty, second_number_dirty;

    scanf("%f %f", &first_number_dirty, &second_number_dirty);

    if (!isInteger(first_number_dirty) || !isInteger(second_number_dirty)) {
        return 1;
    }

    int first_number = first_number_dirty;
    int second_number = second_number_dirty;

    printf(
        "%d, %d, %d ",
        sum(first_number, second_number),
        subtraction(first_number, second_number),
        multiplication(first_number, second_number));

    if (second_number == 0) {
        printf("n/a");
    } else {
        printf("%d", division(first_number, second_number));
    }

    return 0;
}
