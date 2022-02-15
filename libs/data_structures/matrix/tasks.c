//
// Created by Donpad on 14.02.2022.
//

#include "tasks.h"
#include "matrix.h"
#include <stddef.h>
#include "array.h"
#include <malloc.h>

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
int getMinNegative(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return -min;
}


void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMinNegative);
}

/// task 4
matrix mulMatrices(matrix m1, matrix m2) {
    matrix c = getMemMatrix(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            c.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                c.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return c;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        matrix z = mulMatrices(*m, *m);
        swap_(m, &z, sizeof(matrix));
        freeMemMatrix(z);
    }
}

/// task 5

void transposeIfMatrixHasEqualSumOfRows(matrix m){
    long long rowSums[m.nRows];
    for (int row = 0; row < m.nRows; ++row) {
        rowSums[row] = getSum(m.values[row], m.nCols);
    }
    if(isUnique(rowSums, m.nRows))
        transposeSquareMatrix(m);
}





