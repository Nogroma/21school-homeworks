// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS_COUNT 100    // высота
#define MAX_COLUMN_COUNT 100  // ширина

int **create_static_array();
int **create_dynamic_first_array(int row_count, int column_count);
int **create_dynamic_second_array(int row_count, int column_count);
int **create_dynamic_third_array(int row_count, int column_count);
void input_matrix(int **array, int row_count, int column_count);
void output_matrix(int **array, int row_count, int column_count);
void output_array(int *array, int length);

void input_matrix(int **array, int row_count, int column_count) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            if (scanf("%d", &array[i][j]) != 1) {
                printf("n/a");
            }
        }
    }
}

void output_matrix(int **array, int row_count, int column_count) {
    printf("Вывод элеменов массива:\n");
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            printf("%d ", array[i][j]);
        }
    }
}

void output_array(int *array, int length) {
    printf("\n-------------\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
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

int *find_max(int **array, int row_count, int column_count) {
    int *max_elements;

    for (int i = 0; i < row_count; i++) {
        int max_in_row = array[i][0];

        for (int j = 0; j < column_count; j++) {
            if (array[i][j] > max_in_row) {
                max_in_row = array[i][j];
            }
        }

        max_elements[i] = max_in_row;
    }

    return max_elements;
}

int *find_min(int **array, int row_count, int column_count) {
    int *min_elements;
    printf("SUKA 2\n");

    for (int i = 0; i < row_count; i++) {
        printf("SUKA 3\n");
        int min_in_row = array[i][0];

            printf("SUKA 4\n");
        for (int j = 0; j < column_count; j++) {
            if (array[i][j] < min_in_row) {
                printf("SUKA 5\n");
                min_in_row = array[i][j];
            }
        }

        min_elements[i] = min_in_row;
    }

    return min_elements;
}

int main() {
    int **matrix = NULL;

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
            matrix = create_static_array();
            break;
        case 2:
            matrix = create_dynamic_first_array(rows, cloumns);
            break;
        case 3:
            matrix = create_dynamic_second_array(rows, cloumns);
            break;
        case 4:
            matrix = create_dynamic_third_array(rows, cloumns);
            break;
        default:
            break;
    }

    input_matrix(matrix, rows, cloumns);
    output_matrix(matrix, rows, cloumns);

    output_array(find_max(matrix, rows, cloumns), rows);

    int *min_in_rows = find_min(matrix, rows, cloumns);
    output_array(min_in_rows, rows);

    switch (choice) {
        case 2:
            free(matrix);

            break;
        case 3:
            for (int i = 0; i < rows; i++) {
                free(matrix[i]);
            }

            free(matrix);

            break;
        case 4:
            free(matrix);

            break;
        default:
            break;
    }
}
