#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);
/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *array = (int *)malloc(sizeof(int) * n * m);
    int array_index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[array_index] = matrix[i][j];
            array_index++;
        }
    }

    for (int i = 0; i < array_index - 1; i++) {
        for (int j = 0; j < array_index - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }

    int k = -1;

    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                result_matrix[i][j] = array[++k];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                result_matrix[i][j] = array[++k];
            }
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *array = (int *)malloc(sizeof(int) * n * m);
    int array_index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[array_index] = matrix[i][j];
            array_index++;
        }
    }

    for (int i = 0; i < array_index - 1; i++) {
        for (int j = 0; j < array_index - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }

    int k = -1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = array[++k];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = array[++k];
            }
        }
    }
}

void input(int **matrix, int n, int m) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
            }
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **allocate_memory_for_matrix(int row_count, int column_count) {
    int **matrix = malloc(row_count * column_count * sizeof(int) + row_count * sizeof(int *));
    int *ptr = (int *)(matrix + row_count);

    for (int i = 0; i < row_count; i++) {
        matrix[i] = ptr + column_count * i;
    }

    return matrix;
}

int main() {
    int n, m;

    printf("Введите высоту и ширину матрицы: \n");
    scanf("%d %d", &n, &m);

    int **matrix = allocate_memory_for_matrix(n, m);
    int **result = allocate_memory_for_matrix(n, m);

    input(matrix, n, m);

    sort_vertical(matrix, n, m, result);
    printf("Вывод элеменов массива змейкой:\n");
    output(result, n, m);

    sort_horizontal(matrix, n, m, result);
    printf("\n");
    output(result, n, m);

    free(matrix);
    free(result);
    return 0;
}
