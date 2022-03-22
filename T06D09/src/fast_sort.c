// Copyright 2022, Nogroma. All rights reserved.
#include <stdio.h>

int ARRAY_LENGTH = 10;

int intput(int *array) {
    printf("Введите массив целых чисел:\n");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("\n n/a");
            return 1;
        }
    }
    return 0;
}

void qsort(int *mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsort(mas, j + 1);
    }
    if (i < size) {
        qsort(&mas[i], size - i);
    }
}

void siftDown(int *numbers, int root, int bottom) {
    int maxChild;  // индекс максимального потомка
    int done = 0;  // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)   // если мы в последнем ряду,
            maxChild = root * 2;  // запоминаем левый потомок
        // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root];  // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else         // иначе
            done = 1;  // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size) {
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

int output(int *array) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

int main() {
    int array[ARRAY_LENGTH];
    int input_code = intput(array);
    if (input_code != 0) {
        printf("n/a");

        return 1;
    }
    // sort(array);
    qsort(array, ARRAY_LENGTH);
    output(array);
    printf("\n");
    heapSort(array, ARRAY_LENGTH);
    output(array);

    return 0;
}
