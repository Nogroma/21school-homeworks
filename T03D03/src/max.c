// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

int main() {
    int first_number, second_number;

    if (scanf("%d %d", &first_number, &second_number) != 2) {
        printf("n/a");

        return 1;
    }

    printf("%d", max(first_number, second_number));

    return 0;
}
