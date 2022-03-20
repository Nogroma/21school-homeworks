// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>

#define ARRAY_LENGTH 10

int intput(int *array) {
    printf("Введите массив целых чисел:\n");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (scanf("%d", array) != 1) {
            return 1;
        }
    }
    return 0;
}

void sort(int *array) {
    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        for (int j = 0; j < ARRAY_LENGTH - i - 1; j++) {
            if (&array[j] > &array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int output(int array) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d ", i);
    }
    return 0;
}

int main() {
    int array;
    int input_code = intput(&array);
    if (input_code != 0) {
        printf("n/a");

        return 1;
    }

    sort(&array);
    output(array);

    return 0;
}
