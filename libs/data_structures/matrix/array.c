//
// Created by Donpad on 29.01.2022.
//

#include "array.h"

void swap(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char t = pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}