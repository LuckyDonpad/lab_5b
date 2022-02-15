//
// Created by Donpad on 14.02.2022.
//

#include "tasks.h"
#include "matrix.h"
#include <stddef.h>
#include "array.h"
#include <malloc.h>
#include <iso646.h>

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
void transposeIfMatrixHasEqualSumOfRows(matrix m) {
    long long rowSums[m.nRows];
    for (int row = 0; row < m.nRows; ++row) {
        rowSums[row] = getSum(m.values[row], m.nCols);
    }
    if (!isUnique(rowSums, m.nRows))
        transposeSquareMatrix(m);
}

/// task 6
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m3 = mulMatrices(m1, m2);
    return (bool) isEMatrix(m3);
}


/// task 7
void getArrayFromLeftDiagonal(matrix m, position pos, int *array, size_t *size) {
    *size = 0;
    int x = pos.rowIndex;
    int y = pos.colIndex;
    while (x >= 0 and y != m.nCols) {
        array[*size] = m.values[x][y];
        *size += 1;
        y++;
        x--;
    }
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int diagonal[m.nRows];
    long long max = 0;
    size_t size = 0;
    for (int i = 0; i < m.nCols - 1; ++i) {
        getArrayFromRightDiagonal(m, (position) {m.nRows - 1, i}, diagonal, &size);
        max += getMax(diagonal, size);
    }

    for (int i = 0; i < m.nCols - 1; ++i) {
        getArrayFromRightDiagonal(m, (position) {i, m.nCols - 1}, diagonal, &size);
        max += getMax(diagonal, size);
    }
    int primeSide = m.nRows < m.nCols ? m.nRows - 1 : m.nCols - 1;
    position primeDiagonal = {primeSide, primeSide};
    getArrayFromRightDiagonal(m, primeDiagonal, diagonal, &size);
    max -= getMax(diagonal, size);

    return max;
}

/// task 8
void getArrayFromRightDiagonal(matrix m, position pos, int *array, size_t *size) {
    *size = 0;
    int x = pos.rowIndex;
    int y = pos.colIndex;
    while (x >= 0 and y >= 0) {
        array[*size] = m.values[x][y];
        *size += 1;
        y--;
        x--;
    }
}

int getMinInArea(matrix m) {
    int diagonal[m.nCols];
    int size = 0;
    position max = getMaxValuePos(m);
    int x = max.rowIndex;
    int y = max.colIndex;
    int min = getElementByPosition(m, max);
    while (x != 0) {
        x--;
        getArrayFromLeftDiagonal(m, (position) {x, y}, diagonal, &size);
        int diagonalMin = getMin(diagonal, size);
        if (diagonalMin < min)
            min = diagonalMin;

        getArrayFromRightDiagonal(m, (position) {x, y}, diagonal, &size);
        diagonalMin = getMin(diagonal, size);
        if (diagonalMin < min)
            min = diagonalMin;
    }
    return min;
}