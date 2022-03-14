// Copyright 2021, Nogroma. All rights reserved.
#include <stdio.h>

int check_divisibility(int a, int b) {
    while (a > 0) {
        a -= b;

        if ((a < b) && (a != 0)) {
            return 0;
        }
    }
    return 1;
}

int get_largest_divisor(int a) {
    if (a < 0)
        a = a * -1;

    for (int i = a; i >= 1; i--) {
        int flag = 1;

        if (check_divisibility(a, i)) {
            for (int j = i - 1; j > 1; j--) {
                if (check_divisibility(i, j)) {
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                return i;
            }
        }
    }

    return 1;
}

int main() {
    int input_number;

    if (scanf("%d", &input_number) != 1 || input_number < 2) {
        printf("n/a");
        return 1;
    }

    printf("%d", get_largest_divisor(input_number));

    return 0;
}
