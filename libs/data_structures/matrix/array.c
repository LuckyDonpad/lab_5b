//
// Created by Donpad on 29.01.2022.
//

#include "array.h"
#include <stdbool.h>

void swap_(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool isUnique(long long *a, int n) {
    bool isUnique = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j])
                isUnique = false;
        }
    }
    return isUnique;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

int getMax(int *array, size_t size) {
    int max = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int getMin(int *array, size_t size) {
    int min = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}