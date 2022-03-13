// Copyright 2021, Nogroma. All rights reserved.
#include <stdio.h>

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
    int first_number, second_number;

    if (scanf("%d %d", &first_number, &second_number) != 2){
        printf("n/a");

        return 1;
    }

    printf(
        "%d %d %d ",
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
