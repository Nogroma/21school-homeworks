#include "data_stat.h"

double max(double *data, int n) {
    double max_value = *data;

    for (double *p = data; p - data < n; p++) {
        if (*data > max_value) {
            max_value = *p;
        }
    }

    return max_value;
}

double min(double *data, int n) {
    int min_value = *data;

    for (double *p = data; p - data < n; p++) {
        if (*p < min_value) {
            min_value = *p;
        }
    }

    return min_value;
}

double variance(double *data, int n) {
    return mean(data, n) / 2;
}

double mean(double *data, int n) {
    return (max(data, n) + min(data, n)) / 2;
}
