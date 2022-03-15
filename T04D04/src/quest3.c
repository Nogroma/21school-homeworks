// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>

int fibonacci(int num) {
    if (num <= 1) {
        return num;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
    int user_input;

    if (scanf("%d", &user_input) != 1 || user_input <= 0) {
        printf("n/a");
        return 1;
    }

    printf("%d ", fibonacci(user_input));

    return 0;
}