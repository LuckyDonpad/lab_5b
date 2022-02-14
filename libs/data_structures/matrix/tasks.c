//
// Created by Donpad on 14.02.2022.
//

#include "tasks.h"
#include "matrix.h"
#include <stddef.h>

/// task 1
void swapRowsWithMinAndMax(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

/// task 2;
int getMaxNegative(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }

    return -max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMaxNegative);
}

/// task 3
int getMinNegative(int *a, int n){
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return -min;
}


void sortColsByMinElement(matrix m){
    insertionSortColsMatrixByColCriteria(m, getMinNegative);
}




