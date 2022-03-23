// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>
#include <stdlib.h>


void intput(int *array, int length) {
    printf("Введите массив целых чисел:\n");
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("n/a");
        }
    }
}

void sort(int *array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = (length - 1); j > i; j--) {
            if (array[j-1] > array[j]) {
                int tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void output(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int ARRAY_LENGTH;
    scanf("%d", &ARRAY_LENGTH);
    int *array;
    array = (int*)malloc(ARRAY_LENGTH * sizeof(int));
    intput(array, ARRAY_LENGTH);
    sort(array, ARRAY_LENGTH);
    output(array, ARRAY_LENGTH);
    free(array);
}
