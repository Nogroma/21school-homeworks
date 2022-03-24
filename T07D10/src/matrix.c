// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS_COUNT 100    // высота
#define MAX_COLUMN_COUNT 100  // ширина

int **create_static_array();
int **create_dynamic_first_array(int row_count, int column_count);
int **create_dynamic_second_array(int row_count, int column_count);
int **create_dynamic_third_array(int row_count, int column_count);
void in_put(int **array, int row_count, int column_count);
void out_put(int **array, int row_count, int column_count);

void in_put(int **array, int row_count, int column_count) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            if (scanf("%d", &array[i][j]) != 1) {
                printf("n/a");
            }
        }
    }
}

void out_put(int **array, int row_count, int column_count) {
    printf("Вывод элеменов массива:\n");
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            printf("%d ", array[i][j]);
        }
    }
}

int **create_static_array() {
    int buffer[MAX_ROWS_COUNT][MAX_ROWS_COUNT];
    static int *arr_matrix[MAX_COLUMN_COUNT];

    for (int i = 0; i < MAX_ROWS_COUNT; i++) {
        arr_matrix[i] = (int *)buffer[0] + i * MAX_COLUMN_COUNT;
    }

    return arr_matrix;
}

int **create_dynamic_first_array(int row_count, int column_count) {
    int **array = malloc(row_count * column_count * sizeof(int) + row_count * sizeof(int *));
    int *ptr = (int *)(array + row_count);

    for (int i = 0; i < row_count; i++) {
        array[i] = ptr + column_count * i;
    }

    return array;
}

int **create_dynamic_second_array(int row_count, int column_count) {
    int **array = malloc(row_count * sizeof(int *));
    for (int i = 0; i < row_count; i++) {
        array[i] = malloc(column_count * sizeof(int));
    }
    return array;
}

int **create_dynamic_third_array(int row_count, int column_count) {
    int **array = malloc(row_count * sizeof(int *));
    int *array_2 = malloc(row_count * column_count * sizeof(int));

    for (int i = 0; i < row_count; i++) {
        array[i] = array_2 + column_count * i;
    }
    return array;
}

int main() {
    int **array = NULL;

    printf("Выберите способ выделения памяти:\n");

    int choice;
    scanf("%d", &choice);

    if (choice > 4 || choice <= 0) {
        printf("n/a");
    }

    int rows, cloumns;

    printf("Введите ширину и высоту массива:\n");
    scanf("%d %d", &rows, &cloumns);

    switch (choice) {
        case 1:
            array = create_static_array();
            break;
        case 2:
            array = create_dynamic_first_array(rows, cloumns);
            break;
        case 3:
            array = create_dynamic_second_array(rows, cloumns);
            break;
        case 4:
            array = create_dynamic_third_array(rows, cloumns);
            break;
        default:
            break;
    }

    in_put(array, rows, cloumns);
    out_put(array, rows, cloumns);

    switch (choice) {
        case 2:
            free(array);

            break;
        case 3:
            for (int i = 0; i < rows; i++) {
                free(array[i]);
            }

            free(array);

            break;
        case 4:
            free(array);

            break;
        default:
            break;
    }

    // int *array;
    // array = (int *)malloc(ARRAY_LENGTH * sizeof(int));
    // intput(array, ARRAY_LENGTH);
    // output(array, ARRAY_LENGTH);
    // free(array);
}
